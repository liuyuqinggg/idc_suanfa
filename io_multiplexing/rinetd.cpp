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

int cmdlistensock = 0; //服务端监听内网客户端的socket
int cmdconnsock = 0; // 内网客户端与服务端的控制通道
 
int main(int argc, char const *argv[])
{
    if(argc != 4){
        printf("Usage: ./rinetd logfile inetd.cnf cmdport\n");
        printf("Usage: ./rinetd /home/lyq/project/io_multiplexing/log/rinetd.logfile /home/lyq/project/io_multiplexing/inetd.cnf 4000\n");
        printf("logfile:本程序的日志文件名\n");
        printf("inetd.cnf:代理服务器配置参数文件\n");
        printf("cmdport:与内网代理程序的通讯端口\n");
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

    //初始化内网监听端口
    if( (cmdlistensock = initserver(atoi(argv[3]))) < 0){
        logfile.Write("iniserver(%d) failed\n",atoi(argv[3]));
            return -1;
    }

    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    int cmdconnsock = accept(cmdlistensock,(struct sockaddr*)&client,&len);
    if(cmdconnsock < 0) {
        return -1;
    }
    
    logfile.Write("%ld  内网代理连接成功(socket=%d).\n",time(0),cmdconnsock);

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

                    char buffer[256];
                    memset(buffer,0,sizeof(buffer));
                    sprintf(buffer,"<dstip>%s</dstip><dstport>%d</dstport>",vroute[i].dstip,vroute[i].dstport);

                    if(send(cmdconnsock,buffer,strlen(buffer),0) < 0 ){
                        logfile.Write("与内网连接通道以断开\n");
                        EXIT(0);
                    }

                    int dstsock = accept(cmdlistensock,(struct sockaddr*)&client,&len);
                    if(dstsock < 0) {
                        close(srcsock);
                        close(dstsock);
                        break;
                    }
                    if(dstsock > MAXSOCK){
                        logfile.Write("连接数超过最大值%d\n",MAXSOCK);break;
                    }

                    
                    

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

                    logfile.Write("accept on port %d client(%d,%d) ok\n",vroute[i].listenport,srcsock,dstsock);

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

