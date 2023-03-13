#include<iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
int main(int argc, char const *argv[])
{

    FILE *fp = fopen("/tmp/tmp.txt","w+");
    int ii = 1;
    cout << "getpid()=" << getpid() << endl;
    cout << "getppid()=" << getppid() << endl;

    int pid = fork(); //调用一次 返回两次  子进程返回0  父进程返回子进程编号

    if(pid == 0){ //child process
        ii = 3;
        
        cout << "child " << ii << endl;

        fprintf(fp,"child say...\n"); //close the file in child process would not affect parent process
        sleep(2);
        fprintf(fp,"child say...\n");
        sleep(2);
        fprintf(fp,"child say...\n");
        sleep(2);
        fprintf(fp,"child say...\n");
        fclose(fp);
    }else{ // parent process
        cout << "parent " << ii << endl;
        fprintf(fp,"parent say...\n");
        fclose(fp); //close the file in parent process would not affect child process
    }

    

   
    return 0;
}
