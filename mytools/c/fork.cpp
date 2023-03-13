#include<iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
int main(int argc, char const *argv[])
{
    cout << "getpid()=" << getpid() << endl;
    cout << "getppid()=" << getppid() << endl;

    sleep(10);

    int pid = fork(); //调用一次 返回两次  子进程返回0  父进程返回子进程编号

    

    printf("%d\n",pid);

    cout << "getpid()=" << getpid() << endl; // 输出两次 子进程父进程都会运行
    cout << "getppid()=" << getppid() << endl; // 输出两次
    return 0;
}
