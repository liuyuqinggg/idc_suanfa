#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<iostream>
#include<stdlib.h>
#include<unistd.h>

#include<string.h>
#include "_public.h"

CSEM sem;// semaphore

struct st_pid{
    int pid;
    char name[51];
};

//  g++ -g 对共享内存用信号量加锁.cpp -I/home/lyq/project/public /home/lyq/project/public/_public.cpp
int main(int argc, char const *argv[])
{
    if(argc < 2) { printf(("Using: ./book procname\n")); return 0;}

    //共享内存的标志
    int shmid;
    //获取或创建共享内存，键值为0x5005
    if((shmid = shmget(0x5005,sizeof(struct st_pid), 0640 | IPC_CREAT)) == -1){
        printf("shmget(0x5005) failed\n");
        return -1;
    }

    if(sem.init(0x5005) == false){
        printf("sem.init(0x5005) failed.\n");
        return -1;
    }

    struct st_pid *stpid = 0;
    if((stpid = (struct st_pid *)shmat(shmid,0,0)) == (void *) -1){
        printf("shmat() failed\n");
        return -1;
    }

    printf("aaa  time=%ld,val=%d\n",time(0),sem.value());
    sem.P();
    printf("bbb  time=%ld,val=%d\n",time(0),sem.value());
    printf("pid=%d,name=%s\n",stpid->pid,stpid->name);
    stpid->pid = getpid();
    sleep(10);
    strcpy(stpid->name,argv[1]);
    printf("pid=%d,name=%s\n",stpid->pid,stpid->name);
    printf("ccc  time=%ld,val=%d\n",time(0),sem.value());

    printf("ddd  time=%ld,val=%d\n",time(0),sem.value());
    sem.V();

    shmdt(stpid);

    if(shmctl(shmid,IPC_RMID,0) == -1){
        printf("shmctl failed.\n");
        return -1;
    }

    return 0;
}

