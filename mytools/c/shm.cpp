#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<iostream>
#include<stdlib.h>
#include<unistd.h>

#include<string.h>

struct st_pid{
    int pid;
    char name[51];
};

int main(int argc, char const *argv[])
{
    
    int shmid;
    if((shmid = shmget(0x5005,sizeof(struct st_pid), 0640 | IPC_CREAT)) == -1){
        printf("shmget(0x5005) failed\n");
        return -1;
    }

    struct st_pid *stpid = 0;
    if((stpid = (struct st_pid *)shmat(shmid,0,0)) == (void *) -1){
        printf("shmat() failed\n");
        return -1;
    }
    printf("pid=%d,name=%s\n",stpid->pid,stpid->name);
    stpid->pid = getpid();
    strcpy(stpid->name,argv[1]);
    printf("pid=%d,name=%s\n",stpid->pid,stpid->name);

    shmdt(stpid);

    if(shmctl(shmid,IPC_RMID,0) == -1){
        printf("shmctl failed.\n");
        return -1;
    }

    return 0;
}

