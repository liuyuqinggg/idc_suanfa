#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <signal.h>


void handler(int sig){
    printf("receive signal %d\n",sig);
}
void alarmFun(int sig){
    printf("receive alarm signal %d\n",sig);
    alarm(3);
}

int main(int argc, char const *argv[])
{

    for (int i = 1; i < 64; i++)
    {
        signal(i,handler);
    }

    // signal(15,SIG_IGN); 
    signal(2,SIG_DFL);
    signal(SIGALRM,alarmFun);

    alarm(3);
    

    while(1){
        sleep(1);
        printf("running...\n");
    }
    return 0;
}
