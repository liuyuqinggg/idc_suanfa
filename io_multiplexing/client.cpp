#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/fcntl.h>
#include <errno.h>



int main(int argc, char const *argv[])
{
    if(argc != 3){
        printf("Usage: ./client ip port\n"); return -1;
    }

    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock < 0){
        perror("socket() failed\n");
        return -1;
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    if(int ret = connect(sock,(struct sockaddr*)&servaddr,sizeof(servaddr)) != 0){
        printf("connect() failed,ret=%d,errno=%d\n",ret,errno);
        
        return -1;
    }
    printf("connect ok\n");

    char buffer[1024];
    for (int i = 0; i < 10000000; i++)
    {
        memset(buffer,0,sizeof(buffer));
        printf("please input:");
        scanf("%s",buffer);
        // strcpy(buffer,"aaaaaaaaaaaaaaa");

        if(send(sock,buffer,sizeof(buffer),0) <= 0){
            printf("send() failed\n");
            close(sock);
            return -1;
        }
        memset(buffer,0,sizeof(buffer));

        if(recv(sock,buffer,sizeof(buffer),0) <=0){
            printf("read failed\n");
            close(sock);
            return -1;
        }

        printf("recv:%s\n",buffer);
    }
    

    

    return 0;
}
