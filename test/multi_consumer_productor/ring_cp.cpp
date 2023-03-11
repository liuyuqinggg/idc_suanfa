#include "ring_queue.hpp"    
#include "Task.hpp"    
#include <time.h>    
#include <string>    
#include <unistd.h>    
using namespace ns_ring_queue;    
using namespace ns_task;    
void* consumer(void* args)    
{    
    RingQueue<Task>* rq = (RingQueue<Task>*)args;    
    while(true)    
    {    
        sleep(1);    
        Task t;    
        rq->Pop(&t);    
        t();    
    }    
    
}    
    
void* producter(void* args)    
{    
    RingQueue<Task>* rq = (RingQueue<Task>*)args;    
    const string ops = "+-*/%";    
    while(true)    
    {    
        sleep(1);    
        int x = rand() % 20 + 1;    
        int y = rand() % 10 + 1;    
        char op = ops[rand() % ops.size()];    
        Task t(x, y, op);       
        printf("我生产的数据是：%d %c %d =? 我是：%lu\n",x ,op ,y, pthread_self());        
        rq->Push(t);    
    }    
    
}    
    
int main()    
{    
    srand((long long)time(nullptr));    
    RingQueue<Task>* rq = new RingQueue<Task>();    
      
    pthread_t c0, c1, c2, c3, p0, p1, p2;                                                                                                                                                                                                                                                                                                                                                                                                                            
    pthread_create(&c0, nullptr, consumer,(void*)rq);    
    pthread_create(&c1, nullptr, consumer,(void*)rq);    
    pthread_create(&c2, nullptr, consumer,(void*)rq);    
    pthread_create(&c3, nullptr, consumer,(void*)rq);    
    pthread_create(&p0, nullptr, producter,(void*)rq);    
    pthread_create(&p1, nullptr, producter,(void*)rq);    
    pthread_create(&p2, nullptr, producter,(void*)rq);    
    
    pthread_join(c0, nullptr);    
    pthread_join(c1, nullptr);    
    pthread_join(c2, nullptr);    
    pthread_join(c3, nullptr);    
    pthread_join(p0, nullptr);    
    pthread_join(p1, nullptr);    
    pthread_join(p2, nullptr);    
    
    
    return 0;    
}