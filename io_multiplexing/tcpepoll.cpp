#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/fcntl.h>
#include <time.h>
#include <sys/epoll.h>



// 初始化监听端口
int initserver(int);

int main(int argc, char const *argv[])
{
    if(argc != 2){
        printf("Usage: ./tcpselect port\n"); return -1;
    }

    int listensock = initserver(atoi(argv[1]));
    printf("listensock=%d\n",listensock);
    if(listensock < 0) {
        printf("initserver() failed.\n");
        return -1;
    }
    //创建epoll句柄
    int epollfd = epoll_create(1);

    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = listensock;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,listensock,&ev);

    struct epoll_event evs[10];
    memset(evs,0,sizeof(evs[0]) * 10);
    while (true)
    {
        
        int infds = epoll_wait(epollfd,evs,10,5000);

        if(infds < 0){
            printf("epoll_wait() failed\n");
            perror("epoll_wait() failed\n");
            break;
        }

        if(infds == 0){
            printf("epoll_wait() timeout\n");
            continue;
        }
       
            
        for (int eventfd = 0; eventfd < infds; eventfd++)
        {
            // printf("events=%d,data.fd=%d\n",evs[eventfd].events,evs[eventfd].data.fd);
            //如果发生事件的是listensock，表示有新的客户连接
            if(evs[eventfd].data.fd == listensock){
                struct sockaddr_in client;
                socklen_t len = sizeof(client);
                int clientsock = accept(listensock,(struct sockaddr*)&client,&len);
                if(clientsock < 0) {
                    perror("accept() failed"); continue;
                }
                printf("%ld  accept client(socket=%d) ok.\n",time(0),clientsock);

                ev.events = EPOLLIN;
                ev.data.fd = clientsock;
                epoll_ctl(epollfd,EPOLL_CTL_ADD,clientsock,&ev);

            }else{
                //如果是客户端连接的sock有时间，表示连接断开或者有报文发送过来
                char buffer[1024];
                memset(buffer,0,sizeof(buffer));
                
                if(recv(evs[eventfd].data.fd,buffer,sizeof(buffer),0) <= 0){ //客户端连接断开
                    printf("%ld  client(eventfd=%d) disconnected\n",time(0),evs[eventfd].data.fd);
                    close(evs[eventfd].data.fd);
                }else{
                    //客户端有报文发送过来
                    // printf("recv(eventfd=%d):%s\n",eventfd,buffer);                 
                    // send(evs[eventfd].data.fd,buffer,strlen(buffer),0);
                    
                } 
            }
        }
        


    }
    

    return 0;
}

int initserver(int port){
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock < 0){
        perror("socket() failed\n");
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
        perror("bind() failed\n"); close(sock);
        return -1;
    }

    if(listen(sock,5) != 0){
        perror("listen() failed\n"); close(sock);
        return -1;
    }

    return sock;
}

