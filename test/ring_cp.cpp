#include "ring_queue.hpp"    
#include <pthread.h>    
#include <time.h>    
#include <unistd.h>    
using namespace ns_ring_queue;    
    
void* consumer(void* args)    
{    
    RingQueue<int>* rq = (RingQueue<int>*)args;    
    while(true)    
    {   
        sleep(1); 
        int data = 0;    
        rq->Pop(&data);    
        printf("消费的数据是：%d\n", data);       
    }    
    
}    
    
void* producter(void* args)    
{    
    RingQueue<int>* rq = (RingQueue<int>*)args;    
    while(true)    
    {    
        sleep(1);
        int data = rand() % 20 + 1;      
        printf("生产的数据是：%d\n", data);    
        rq->Push(data);    
    }    
    
}    
    
int main()    
{    
    srand((long long)time(nullptr));    
    RingQueue<int>* rq = new RingQueue<int>();    
    pthread_t c, p;    
    pthread_create(&c, nullptr, consumer,(void*)rq);    
    pthread_create(&p, nullptr, producter,(void*)rq);    
    
    pthread_join(c, nullptr);    
    pthread_join(p, nullptr);                                                                                                                                                                                                      
    
    return 0;    
}   