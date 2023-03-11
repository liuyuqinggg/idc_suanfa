#include<iostream>
#include<signal.h>
#include<stdlib.h>

long long count;

void catch2(int sig){
    std::cout << "catch alarm count = " << count << "\n";
}

int main(int argc, char const *argv[])
{
    signal(SIGALRM,catch2);
    alarm(1);
    while(1){
        count++;
    }
    return 0;
}
