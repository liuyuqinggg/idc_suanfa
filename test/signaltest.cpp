#include<iostream>
#include<signal.h>
#include<stdlib.h>

void catch2(int sig){
    std::cout << "catch signal" << sig << "\n";
}

int main(int argc, char const *argv[])
{
    signal(2,catch2);
    while(1){
        sleep(1);
    }
    return 0;
}
