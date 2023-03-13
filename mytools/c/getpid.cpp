#include<iostream>
#include <sys/types.h>
#include <unistd.h>



using namespace std;
int main(int argc, char const *argv[])
{
    cout << "getpid()=" << getpid() << endl;
    cout << "getppid()=" << getppid() << endl;
    return 0;
}
