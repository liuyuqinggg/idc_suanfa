#include<iostream>
#include<signal.h>
#include<stdlib.h>


void hander(int signo)    
{    
  printf("%d阻塞结束\n",signo);    
}    

void signal_printf(sigset_t* pending){ //打印思路很简单，若标记位为1则打印1，若为0则打印0    
  for (int i = 1; i < 31; i++){    
    if (sigismember(pending, i)){    
      printf("1");    
    }    
    else {    
      printf("0");    
    }    
  }    
  printf("\n");    
} 

int main()    
{    
  sigset_t set,oset;    
  sigemptyset(&set);    
  sigemptyset(&oset);    
  sigaddset(&set,2);    
  sigprocmask(SIG_SETMASK,&set,&oset);//将2阻塞    
    
  signal(2,hander);//捕获2信号    
    
  sigset_t pending;    
  int count=0;    
  while(1)    
  {    
    sigpending(&pending);//获取未决信号集    
    //每隔一秒打印未决信号集    
    signal_printf(&pending);    
    sleep(1);    
    count++;    
    if(count==10)    
    {    
      //十秒后解除阻塞
      sigprocmask(SIG_SETMASK,&oset,NULL); 
    }
  }
  return 0;                                                                                                                                                             
}