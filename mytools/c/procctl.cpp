#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{

    if(argc < 3){
        printf("Using:./procctl timetvl program argv ...\n");
        printf("Example:.~/project/mytools/bin/procctl 5 /usr/bin/tar zcvf /tmp/tmp.tgz /usr/include\n\n");

        return -1;
    }

    for (int i = 0; i < 64; i++)
    {
        signal(i,SIG_IGN);
        close(i);
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
            wait(&status);
            sleep(atoi(argv[1]));
        }
        
    }
    
}
