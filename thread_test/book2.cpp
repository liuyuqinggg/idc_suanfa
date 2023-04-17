#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int var = 0;

void *thmain1(void *arg);
void *thmain2(void *arg);

//线程共享进程数据
int main(int argc, char const *argv[])
{

    pthread_t thid1 = 0;
    pthread_t thid2 = 0;
    
    if(pthread_create(&thid1, NULL, thmain1, NULL) != 0){
        printf("pthread_create failed\n");
        return -1;
    } 
    if(pthread_create(&thid2, NULL, thmain2, NULL) != 0){
        printf("pthread_create failed\n");
        return -1;
    } 

    pthread_join(thid1,NULL);
    pthread_join(thid2,NULL);

    return 0;
}

void *thmain1(void *arg){
    for (int i = 0; i < 500; i++)
    {
        printf("thmain1  %d\n",var++);
        sleep(1);
        fflush(stdout);
    }
    return NULL;
}

void *thmain2(void *arg){
    for (int i = 0; i < 500; i++)
    {
        printf("thmain2  %d\n",var);
        sleep(1);
        fflush(stdout);
    }
    return NULL;
}
