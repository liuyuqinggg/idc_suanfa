#include<iostream>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include<sys/types.h>
#include<sys/wait.h>

using namespace std;

void* func(int sig){
    wait(NULL);
    return NULL;
}
int main(int argc, char const *argv[])
{

    signal(SIGCHLD,SIG_IGN);

    int pid = fork(); //调用一次 返回两次  子进程返回0  父进程返回子进程编号

    if(pid == 0){ //child process
        
        cout << "child running" << endl;

        
        sleep(20);
        
    }else{ // parent process

        cout << "parent running" << endl;

        // wait(NULL);
        sleep(10);
    }

    

   
    return 0;
}
