//网络代理服务程序

#include "../public/_public.h"

//代理路由参数的结构体
struct st_route{
    int listenport; //本地监听通讯端口
    char dstip[31]; //目标主机的ip
    int dstport; //目标主机通讯端口
    int listensock;
}stroute;

vector<st_route> vroute;

bool load_route(const char *inifile);

void EXIT(int sig);


CLogFile logfile;


// 初始化监听端口
int initserver(int);

#define MAXSOCK 1024
int clientsock[MAXSOCK]; //存放每个sock连接对端的sock值
int clientatime[MAXSOCK]; //存放每个sock连接最后一次收发报文的时间

int connectdst(char *,int); //连接对端ip
 
int main(int argc, char const *argv[])
{
    if(argc != 3){
        printf("Usage: ./inetd /home/lyq/project/io_multiplexing/log/inetd.logfile /home/lyq/project/io_multiplexing/inetd.cnf\n");
        return -1;
    }

    CloseIOAndSignal(); 
    signal(SIGINT,EXIT); 
    signal(SIGTERM,EXIT);

    if(logfile.Open(argv[1],"a+") == false){
        printf("打开%s失败\n",argv[1]);
    }

    if(load_route(argv[2]) == false){
        logfile.Write("打开%s失败\n",argv[2]);
    }

    logfile.Write("加载路由代理参数%s成功\n",argv[2]);

    for (int i = 0; i < vroute.size(); i++)
    {
        if((vroute[i].listensock = initserver(vroute[i].listenport)) < 0){
            logfile.Write("iniserver(%d) failed\n",vroute[i].listenport);
            return -1;
        }

        fcntl(vroute[i].listensock,F_SETFL,fcntl(vroute[i].listensock,F_GETFD,0) | O_NONBLOCK);
    }
    

    //创建epoll句柄
    int epollfd = epoll_create(1);
    struct epoll_event ev;

    for (int i = 0; i < vroute.size(); i++)
    {
        ev.events = EPOLLIN;
        ev.data.fd = vroute[i].listensock;
        epoll_ctl(epollfd,EPOLL_CTL_ADD,vroute[i].listensock,&ev);
    }

    struct epoll_event evs[10];
    while (true)
    {
        
        int infds = epoll_wait(epollfd,evs,10,5000);

        if(infds < 0){
            logfile.Write("epoll_wait() failed\n");
            break;
        }

        if(infds == 0){
            continue;
        }
       
            
        for (int eventfd = 0; eventfd < infds; eventfd++)
        {
            // logfile.Write("events=%d,data.fd=%d\n",evs[eventfd].events,evs[eventfd].data.fd);
            //如果发生事件的是listensock，表示有新的客户连接
            int i = 0;
            for (; i < vroute.size(); i++)
            {
                if(evs[eventfd].data.fd == vroute[i].listensock){
                    struct sockaddr_in client;
                    socklen_t len = sizeof(client);
                    int srcsock = accept(vroute[i].listensock,(struct sockaddr*)&client,&len);
                    if(srcsock < 0) {
                        break;
                    }
                    if(srcsock > MAXSOCK){
                        logfile.Write("连接数超过最大值%d\n",MAXSOCK);break;
                    }
                    logfile.Write("%ld  accept client(socket=%d) ok.\n",time(0),srcsock);

                    //向目标ip和端口发起连接
                    int dstsock = connectdst(vroute[i].dstip,vroute[i].dstport);
                    if(dstsock < 0) {
                        break;
                    }
                    if(dstsock > MAXSOCK){
                        logfile.Write("连接数超过最大值%d\n",MAXSOCK);break;
                    }

                    logfile.Write("accept on port %d client(%d,%d) ok\n",vroute[i].listenport,srcsock,dstsock);
                    // 

                    ev.events = EPOLLIN;
                    ev.data.fd = srcsock;
                    epoll_ctl(epollfd,EPOLL_CTL_ADD,srcsock,&ev);

                    ev.events = EPOLLIN;
                    ev.data.fd = dstsock;
                    epoll_ctl(epollfd,EPOLL_CTL_ADD,dstsock,&ev);

                    clientsock[srcsock] = dstsock;
                    clientsock[dstsock] = srcsock;
                    clientatime[srcsock] = time(0);
                    clientatime[dstsock] = time(0);

                    break;

                }

                if(i < vroute.size()) continue;
                /////////////////////////////////////////////////////////////////////
                
            }

            //如果是客户端连接的sock有时间，表示连接断开或者有报文发送过来
            char buffer[5000];
            memset(buffer,0,sizeof(buffer));
            int buflen =0;
            if((buflen = recv(evs[eventfd].data.fd,buffer,sizeof(buffer),0)) <= 0){ //客户端连接断开
                logfile.Write("%ld  client(%d,%d) disconnected\n",time(0),evs[eventfd].data.fd,clientsock[evs[eventfd].data.fd]);
                close(evs[eventfd].data.fd);
                close(clientsock[evs[eventfd].data.fd]);

                clientsock[clientsock[evs[eventfd].data.fd]] = 0;
                clientsock[evs[eventfd].data.fd] = 0;
                continue;

            }

            //客户端有报文发送过来
            logfile.Write("from %d to %d,%d bytes\n",evs[eventfd].data.fd,clientsock[evs[eventfd].data.fd],buflen);
            send(clientsock[evs[eventfd].data.fd],buffer,buflen,0);
                
            
            
        }
        


    }
    

    return 0;
}

void EXIT(int sig){
    logfile.Write("进程退出， sig=%d\n",sig);
    // 关闭全部监听sock
    for (int i = 0; i < vroute.size(); i++)
    {
        close(vroute[i].listensock);
    }

    for (int i = 0; i < MAXSOCK; i++)
    {
        if(clientatime[i] > 0) close(clientsock[i]);
    }
    
    exit(0);
}

int connectdst(char *ip,int port){
    logfile.Write("try connect %s:%d\n",ip,port);
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock < 0){
        logfile.Write("socket() failed\n");
        return -1;
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_port = htons(port);

    fcntl(sock,F_SETFL,fcntl(sock,F_GETFD,0) | O_NONBLOCK);
    connect(sock,(struct sockaddr*)&servaddr,sizeof(servaddr));
    logfile.Write("connect ok\n");

    return sock;
}

int initserver(int port){
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock < 0){
        logfile.Write("socket() failed\n");
        return -1;
    }

    int opt = 1; unsigned int len = sizeof(opt);
    setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&opt,len);

    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port); //要加htons()，不然无法成功监听

    if(bind(sock,(struct sockaddr*)&servaddr,sizeof(servaddr)) < 0){
        logfile.Write("bind() failed\n"); close(sock);
        return -1;
    }

    if(listen(sock,5) != 0){
        logfile.Write("listen() failed\n"); close(sock);
        return -1;
    }

    return sock;
}

bool load_route(const char *inifile){
    CFile File;
    if(File.Open(inifile,"r") == false){
        logfile.Write("打开%s失败\n",inifile);
    }

    char buffer[1024];
    CCmdStr CmdStr;
    while (true)
    {
        memset(buffer,0,sizeof buffer);
        if(File.FFGETS(buffer,200) == false) break;
        char *pos = strstr(buffer,"#");
        if(pos != 0) pos[0] = 0;
        DeleteRChar(buffer,' ');
        UpdateStr(buffer,"  "," ",true);
        CmdStr.SplitToCmd(buffer," ");
        if(CmdStr.CmdCount() != 3) continue;

        memset(&stroute,0,sizeof stroute);
        CmdStr.GetValue(0,&stroute.listenport);
        CmdStr.GetValue(1,stroute.dstip);
        CmdStr.GetValue(2,&stroute.dstport);

        vroute.push_back(stroute);
    }

    return true;


}

