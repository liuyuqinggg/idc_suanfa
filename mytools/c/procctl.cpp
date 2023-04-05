#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "_public.h"

CLogFile logfile;

int main(int argc, char *argv[])
{

    if(argc < 3){
        printf("Using:./procctl timetvl program argv ...\n");
        printf("Example:.~/project/mytools/bin/procctl 5 /usr/bin/tar zcvf /tmp/tmp.tgz /usr/include\n\n");
        printf("Example:.~/project/mytools/bin/procctl 60 /home/lyq/project/myidc/bin/crtsurfdata /home/lyq/project/myidc/ini/stcode.ini /home/lyq/project/tem/surfdata\
                 /home/lyq/project/myidc/log/crtsurfdata.log xml,json,csv\n\n");
        printf("本程序是服务程序的调度程序，周期性启动服务程序或shell脚本。\n");
        printf("timetvl 运行周期，单位：秒。被调度的程序运行结束后，在timetvl秒后会被procctl重新启动。\n");
        printf("program 被调度的程序名，必须使用全路径。\n");
        printf("argvs   被调度的程序的参数。\n");
        printf("注意，本程序不会被kill杀死，但可以用kill -9强行杀死。\n\n\n");
        return -1;
    }

    if(logfile.Open("/home/lyq/project/log/procctl.log","a") == false){
        printf("logfile.Open(\"/home/lyq/project/log/procctl.log\",\"a\") failed!\n");
        return -1;
    }

    for (int i = 0; i < 64; i++)
    {
        signal(i,SIG_IGN);
        // close(i);
    }


    if(fork() != 0) exit(0);

    signal(SIGCHLD,SIG_DFL);
    

    char*  pargv[argc];
    for(int i = 2; i < argc; i++){
        pargv[i - 2] = argv[i];
    }

    pargv[argc - 2] = NULL;
    //./procctl 5 /usr/bin/ls -lt /tmp
    while (true)
    {
        if(fork() == 0){
            // execl(argv[2],argv[2],argv[3],argv[4],(char*)0 );
            execv(argv[2], pargv);
            
            exit(0);
        }else{
            int status;
            int child_pid = wait(&status);
            logfile.Write("pid=%d --- status=%d",child_pid,status);
            sleep(atoi(argv[1]));
        }
        
    }
    
}
