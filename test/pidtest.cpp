#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<string>


int main(int argc, char const *argv[])
{
    printf("getpid()=%d\n",getpid());
    
    printf("getppid()=%d\n",getppid());

    sleep(50);
    return 0;
}
