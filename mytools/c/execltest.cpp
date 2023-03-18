#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<iostream>

//  The  exec() family of functions replaces the current process image with a new process image.
int main(int argc, char *argv[])
{

    std::cout << "aaaa\n";

    execl("/usr/bin/ls","ls", "-a", NULL);

    std::cout << "bbbb\n"; //成功调用 execl之后，进程空间被新的进程替换  bbbb不会输出
    
}
