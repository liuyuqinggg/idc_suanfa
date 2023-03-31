#include "_public.h"

#define MAXNUMP_ 1000
#define SHMKEYP_ 0x5095 //shared memory address

struct st_pinfo{
    int pid;  // process id
    char pname[51]; //process name
    int timeout;  // expired time
    time_t atime;  // last heartbeat time  ,  if (current time - atime ) > timeout,that means the process has problems
};


class CActive{
    public:
        int m_shmid;
        CSEM sem;
        int m_pos;
        struct st_pinfo *m_shm;
    public:
        CActive();

        bool AddPInfo(const int timeout,const char *pname);

        bool UptATime();

        ~CActive();
};

CActive::CActive(){
    m_shmid = -1;
    m_pos = -1;
    m_shm = 0;

}

bool CActive::AddPInfo(const int timeout,const char *pname){
    //创建或获取共享内存，大小为 n * sizeof(struct st_pinfo)
    int m_shmid = 0;
    if((m_shmid = shmget(SHMKEYP_,MAXNUMP_ * sizeof(struct st_pinfo),0640 | IPC_CREAT)) == -1){
        printf("shmget(%x) failed\n",SHMKEYP_);
        return false;
    }
    if(sem.init(0x5005) == false){
        printf("sem.init(0x5005) failed.\n");
        return false;
    }

    //将共享内存连接到当前进程的地址空间
    m_shm = (struct st_pinfo *)shmat(m_shmid,0,0);

    //创建当前进程心跳信息结构提变量，把本进程的信息填进去
    int cur_pid = getpid();
    struct st_pinfo stpinfo;
    memset(&stpinfo,0,sizeof(struct st_pinfo));
    stpinfo.pid = cur_pid;
    STRNCPY(stpinfo.pname,sizeof(stpinfo.pname),pname,50);
    stpinfo.timeout = timeout;
    stpinfo.atime = time(0);

    

    sem.P(); //加锁粒度越小越好
    //在共享内存中查找一个空位置，把当前进程的心跳信息存入共享内存中,把共享内存当成结构体数组，如果结构体中的pid==0,表示是一个空位置
    for (int i = 0; i < MAXNUMP_; i++)
    {
        if(m_shm[i].pid == 0 || m_shm[i].pid == cur_pid){ //m_shm[i].pid == cur_pid 用来解决上一个进程异常退出，
                                                            //没有清理自己的心跳信息，而当前进程的pid == 之前异常退出进程的pid。此时应该重用此心跳结构体
            m_pos = i;
            break;
        }
    }
    // sem.V();//不能放在这里，因为心跳结构体还没写入到共享内存

    if(m_pos == -1){
        printf("共享内存空间已经用完。\n");
        sem.V();
        return false;
    }

    memcpy(&m_shm[m_pos],&stpinfo,sizeof(stpinfo));
    sem.V();

    return true;
}

bool CActive::UptATime(){
    if(m_pos == -1) return false;
    m_shm[m_pos].atime = time(0);
    return true;
}

CActive::~CActive(){

    if(m_pos == -1) return;

    //把当前进程心跳信息从共享内存中移除
    m_shm[m_pos].pid = 0;

    //把当前共享内存从当前进程中分离
    shmdt(m_shm);
}

int main(int argc, char const *argv[])
{
    if(argc < 2) { printf(("Using: ./book procname\n")); return 0;}
    
    CActive cactive;
    cactive.AddPInfo(30,argv[1]);
    while (true)
    {
        cactive.UptATime();
        sleep(10);
    }
    
    return 0;
    
}
