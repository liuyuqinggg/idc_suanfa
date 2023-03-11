#pragma once    
#include <iostream>    
#include <vector>    
#include <semaphore.h>    
#include <pthread.h>    
using namespace std;    
    
namespace ns_ring_queue    
{    
    const int g_cap_default = 10;    
    template <class T>    
    class RingQueue    
    {    
    private:    
        vector<T> ring_queue_;    
        int cap_;    
        //生产者关心空位置资源    
        sem_t blank_sem_;    
        //消费者关心数据    
        sem_t data_sem_;    
        int c_step_;    
        int p_step_;    
        pthread_mutex_t c_mtx_;    
        pthread_mutex_t p_mtx_;    
    
    public:    
        RingQueue(int cap = g_cap_default):ring_queue_(cap), cap_(cap)    
        {    
            sem_init(&blank_sem_, 0, cap);    
            sem_init(&data_sem_, 0, 0);    
            c_step_ = p_step_ = 0;    
    
            pthread_mutex_init(&c_mtx_, nullptr);    
            pthread_mutex_init(&p_mtx_, nullptr);    
        }    
        ~RingQueue()    
        {    
            sem_destroy(&blank_sem_);    
            sem_destroy(&data_sem_);    
    
            pthread_mutex_destroy(&c_mtx_);    
            pthread_mutex_destroy(&p_mtx_);    
        }    
    public:    
        void Push(const T& in)    
        {    
            //生产接口    
            sem_wait(&blank_sem_);//p空位置    
    
            pthread_mutex_lock(&p_mtx_);    
            ring_queue_[p_step_] = in;    
            p_step_++;                                                                                                                                                                                                                                                                                                                                                                                                                                                 
            p_step_ %= cap_;                                                                             
            pthread_mutex_unlock(&p_mtx_);                                                               
                                                                                                         
            sem_post(&data_sem_);//v数据                                                                 
        }                                                                                                
        void Pop(T* out)                                                                                 
        {                                                                                                
             //消费接口                                                                                  
            sem_wait(&data_sem_);//p数据                                                                 
                                                                                                         
            pthread_mutex_lock(&c_mtx_);                                                                 
            *out = ring_queue_[c_step_];                                                                 
            c_step_++;                                                                                   
            c_step_ %= cap_;                                                                             
            pthread_mutex_unlock(&c_mtx_);                                                               
                                                                                                         
            sem_post(&blank_sem_);//v空位置                                                              
        }                                                                                                
    };                                                                                                   
}