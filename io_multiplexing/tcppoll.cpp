#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/fcntl.h>
#include <time.h>
#include <poll.h>
#define MAXNFDS 1000


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

    
    struct pollfd fds[MAXNFDS];
    for (int i = 0; i < MAXNFDS; i++)
    {
        fds[i].fd = -1;
    }
        
    fds[listensock].fd = listensock;
    fds[listensock].events = POLLIN;
    int maxfd = listensock;

    while (true)
    {
        int infds = poll(fds,maxfd+1,-1);

        if(infds < 0){
            printf("poll() failed\n");
            perror("poll() failed\n");
            break;
        }

        if(infds == 0){
            printf("poll() timeout\n");
            continue;
        }

        
        
            
        for (int eventfd = 0; eventfd <= maxfd; eventfd++)
        {
            if(fds[eventfd].fd == -1){
                continue;
            }

            if((fds[eventfd].revents & POLLIN) == 0){
                continue;
            }
            fds[eventfd].revents=0;

            
            //如果发生事件的是listensock，表示有新的客户连接
            if(eventfd == listensock){
                struct sockaddr_in client;
                socklen_t len = sizeof(client);
                int clientsock = accept(listensock,(struct sockaddr*)&client,&len);
                if(clientsock < 0) {
                    perror("accept() failed"); continue;
                }
                printf("%ld  accept client(socket=%d) ok.\n",time(0),clientsock);

                fds[clientsock].fd = clientsock;
                fds[clientsock].events = POLLIN;
                fds[clientsock].revents = 0;

                if(clientsock > maxfd) maxfd = clientsock;
            }else{
                //如果是客户端连接的sock有时间，表示连接断开或者有报文发送过来
                char buffer[1024];
                memset(buffer,0,sizeof(buffer));
                
                if(recv(eventfd,buffer,sizeof(buffer),0) <= 0){ //客户端连接断开
                    printf("%ld  client(eventfd=%d) disconnected\n",time(0),eventfd);
                    close(eventfd);

                    fds[eventfd].fd = -1;

                    if(eventfd == maxfd){
                        for (int i = maxfd; i >= 0; i--)
                        {
                            if(fds[i].fd != -1 ){
                                maxfd = i;
                                break;
                            }
                        }
                        
                    }
                }else{
                    //客户端有报文发送过来
                    printf("recv(eventfd=%d):%s\n",eventfd,buffer);
                    fd_set tmpfds;
                    FD_ZERO(&tmpfds);
                    FD_SET(eventfd,&tmpfds);
                    if(select(eventfd + 1, NULL,&tmpfds,NULL,NULL) <= 0){
                        perror("select() failed\n");
                    }else{
                        send(eventfd,buffer,strlen(buffer),0);
                    }
                    
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

