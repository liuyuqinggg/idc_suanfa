//网络代理服务程序

#include "../public/_public.h"




void EXIT(int sig);


CLogFile logfile;

int cmdconnsock = 0;



#define MAXSOCK 1024
int clientsock[MAXSOCK]; //存放每个sock连接对端的sock值
int clientatime[MAXSOCK]; //存放每个sock连接最后一次收发报文的时间

int connectdst(char *,int); //连接对端ip
 
int main(int argc, char const *argv[])
{
    if(argc != 4){
        printf("Usage: ./rinetdin logfile ip port\n");
        printf("Example: ./rinetdin /home/lyq/project/io_multiplexing/log/rinetdin.logfile 127.0.0.1 4000\n");
        printf("logfile:本程序的日志文件名\n");
        printf("ip:外网代理服务器的地址\n");
        printf("port:外网代理服务器的端口\n");
        return -1;
    }

    CloseIOAndSignal(); 
    signal(SIGINT,EXIT); 
    signal(SIGTERM,EXIT);

    if(logfile.Open(argv[1],"a+") == false){
        printf("打开%s失败\n",argv[1]);
    }

    //建立内网程序与外网程序的通道
    CTcpClient TcpClient;
    if(TcpClient.ConnectToServer(argv[2],atoi(argv[3])) == false){
        logfile.Write("TcpClient.ConnectToServer(%s,%d)) failed\n",argv[2],atoi(argv[3]));
        return -1;
    }

    logfile.Write("连接外网代理服务器成功\n");

    cmdconnsock = TcpClient.m_connfd;
    fcntl(cmdconnsock,F_SETFL,fcntl(cmdconnsock,F_GETFD,0) | O_NONBLOCK);

    //创建epoll句柄
    int epollfd = epoll_create(1);
    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = cmdconnsock;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,cmdconnsock,&ev);

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
            
            
           /* if(evs[eventfd].data.fd == vroute[i].listensock){
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

            } */

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
