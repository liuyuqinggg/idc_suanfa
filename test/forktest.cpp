#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<string>
#include<signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void func(int sig){
    std::cout << "func\n";
    int sts;
    wait(&sts);
}

int main(int argc, char const *argv[])
{
    // signal(SIGCHLD,SIG_IGN);
    signal(SIGCHLD,func);

    FILE *fp = fopen("/tmp/tmp.txt2","w+");
    fprintf(fp,"hello\n");
    fflush(fp);


    int i = 1;
    int pid = fork();

    if(pid == 0){

        std::cout << "这是子进程" << getpid() << "\n";
        // std::cout << i++ << std::endl;
        // std::cout << i++ << std::endl;
        // std::cout << i++ << std::endl;
        // std::cout << i++ << std::endl;

        // fprintf(fp,"子进程hello\n");

        sleep(10);
    }

    if(pid > 0){
        std::cout << "这是父进程" << getpid() << "\n";
        // std::cout << i << std::endl;
        // fprintf(fp,"父进程hello\n");
        sleep(15);
    }

    
    return 0;
}