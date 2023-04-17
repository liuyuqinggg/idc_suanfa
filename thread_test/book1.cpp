#include <stdio.h>
#include <pthread.h>
#include <unistd.h>



void *thmain(void *arg);

// 演示线程创建
int main(int argc, char const *argv[])
{

    pthread_t thid = 0;
    
    if(pthread_create(&thid, NULL, thmain, NULL) != 0){
        printf("pthread_create failed\n");
        return -1;
    } 

    pthread_join(thid,NULL);

    return 0;
}

void *thmain(void *arg){
    for (int i = 0; i < 500; i++)
    {
        printf("uuuu\n");
        sleep(1);
        fflush(stdout);
    }
    return NULL;
}
