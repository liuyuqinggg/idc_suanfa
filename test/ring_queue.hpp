#pragma once    
#include <iostream>    
#include <vector>    
#include <semaphore.h>    
    
using namespace std;    
    
namespace ns_ring_queue    
{    
    const int g_cap_default = 10; //假设环形队列能存放10个数据   
    template <class T>    
    class RingQueue    
    {    
    private:    
        vector<T> ring_queue_; //环形队列   
        int cap_; //环形队列的容量上限  
             
        sem_t blank_sem_; //生产者关心空位置资源（信号量）               
        sem_t data_sem_;  //消费者关心数据（信号量）
   
        int c_step_; //记录消费者的下标   
        int p_step_; //记录生产者的下标  
    public:    
        RingQueue(int cap = g_cap_default):ring_queue_(cap), cap_(cap)    
        {    
            sem_init(&blank_sem_, 0, cap); //初始化空间资源（信号量）   
            sem_init(&data_sem_, 0, 0);    //初始化数据资源（信号量）
            c_step_ = p_step_ = 0;    
        }    
        ~RingQueue()    
        {    
            sem_destroy(&blank_sem_);    
            sem_destroy(&data_sem_);    
        }    
    public:    
        void Push(const T& in)//生产接口    
        {        
            sem_wait(&blank_sem_);//p空位置（申请空间信号量）
    
            ring_queue_[p_step_] = in; //向环形队列中放数据
   
            sem_post(&data_sem_);//v数据 （发布数据信号量）
  
            p_step_++;    
            p_step_ %= cap_;    
        }    
        void Pop(T* out)//消费接口    
        {    
            sem_wait(&data_sem_);//p数据 （申请数据信号量）
   
            *out = ring_queue_[c_step_]; //从环形队列中取数据
                                                                                                                                                                                                                                                                                                                                   
            sem_post(&blank_sem_);//v空位置 （发布空间信号量）
   
            c_step_++;    
            c_step_ %= cap_;   
        }    
    };    
}