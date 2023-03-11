#pragma once                                                                                                                                                                                                                                                                                                                                                                
#include <iostream>    
#include <pthread.h>    
using namespace std;    
    
namespace ns_task    
{    
    class Task    
    {    
    private:    
        int x_;    
        int y_;    
        char op_;//用来表示：+ 、- 、* 、/ 、%    
    public:    
        Task(){}    
        Task(int x, int y, char op):x_(x), y_(y), op_(op){}    
    
        string show()    
        {    
            string message = to_string(x_);    
            message += op_;    
            message += to_string(y_);    
            message += "=?";    
            return message;    
        }    
        int Run()    
        {    
            int res = 0;    
            switch(op_)    
            {    
                case '+':    
                  res = x_ + y_;    
                  break;    
                case '-':    
                  res = x_ - y_;    
                  break;    
                case '*':    
                  res = x_ * y_;    
                  break;    
                case '/':    
                  res = x_ / y_;    
                  break;    
                case '%':    
                  res = x_ % y_;    
                  break;    
                default:    
                  cout << "bug" << endl;    
                  break;    
            }    
            printf("当前任务正在被：%lu处理，处理结果为：%d %c %d = %d\n",pthread_self(), x_, op_, y_, res);     
            return res;    
        }    
    
        int operator()()    
        {    
            return Run();    
        }    
    
        ~Task(){}    
    };    
} 