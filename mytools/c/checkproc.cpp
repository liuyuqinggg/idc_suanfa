#include "_public.h"
#define MAXNUMP_ 1000
#define SHMKEYP_ 0x5095 //shared memory address

CLogFile logfile;

struct st_pinfo{
    int pid;  // process id
    char pname[51]; //process name
    int timeout;  // expired time
    time_t atime;  // last heartbeat time  ,  if (current time - atime ) > timeout,that means the process has problems
};


int main(int argc, char const *argv[])
{
    // help info
    if(argc != 2){
        printf("\n");
        printf("Usage: ./checkproc logfilename\n");

        printf("Example: ~/project/mytools/bin/procctl 10 ~/project/mytools/bin/checkproc  ~/project/tem/log/checkproc.log\n\n");
        printf("this program is used to check whether background program is timeout,if it timeout, then terminate it.");
        printf("notice:\n");
        printf("1. this program is start by procctl, the recommended period is 10 second.\n");
        printf("2. to avoid be killed by normal user process,this program should started by root user\n");
    }
    
    CloseIOAndSignal(true);

    // open log
    if(logfile.Open(argv[1],"a+") == false){
        printf("logfile.Open(%s,\"a+\")",argv[1]);
    }

    // bind shared memory
    int m_shmid = 0;
    if((m_shmid = shmget(SHMKEYP_,MAXNUMP_ * sizeof(struct st_pinfo),0640 | IPC_CREAT)) == -1){
        logfile.Write("shmget(%x) failed\n",SHMKEYP_);
        return false;
    }

    struct st_pinfo *m_shm = (struct st_pinfo *)shmat(m_shmid,0,0);

    //iterate the shared memory
    for (int i = 0; i < MAXNUMP_; i++)
    {
        if(m_shm[i].pid != 0){ 
            logfile.Write("index=%d,pid=%d,pname=%s,timeout=%d,atime=%d\n", i, m_shm[i].pid, m_shm[i].pname,m_shm[i].timeout,m_shm[i].atime);
            // send signal 0 to the process to confirm whether the process is still alive,if not alive then remove it from the shared memory
            int iret = kill(m_shm[i].pid,0);
            if(iret == -1){
                logfile.Write("process %d(%s) is not alive.\n",m_shm[i].pid,m_shm[i].pname);
                memset(&m_shm[i], 0, sizeof(struct st_pinfo));
            }
            
            //handle the timeout
            time_t now = time(0);
            if(now - m_shm[i].atime > m_shm[i].timeout){
                logfile.Write("进程pid=%d(%s)已经超时。\n",m_shm[i].pid,m_shm[i].pname);

                int pid = m_shm[i].pid;
                char pname[30];
                STRCPY(pname,sizeof pname,m_shm[i].pname);
                //send signal 15
                kill(pid,15);//

                for (int i = 0; i < 5; i++)
                {
                    // logfile.Write("%d\n",m_shm[i].pid);
                    sleep(1);
                    iret = kill(pid,0); //如果m_shm[i].pid进程已经被上一个kill函数杀掉，则此时的m_shm[i].pid为0，所以要用pid 保存m_shm[i].pid
                    if(iret == -1){
                        logfile.Write("进程pid=%d(%s)正常终止。\n",pid,pname);
                        break;
                    } 
                }

                if(iret != -1){
                    kill(m_shm[i].pid,9);
                    logfile.Write("进程pid=%d(%s)被强制终止。\n",pid,pname);
                }

                // remove from shared memory
                memset(&m_shm[i], 0, sizeof(struct st_pinfo));
                
            }
            
        }
    }

    //把当前共享内存从当前进程中分离
    shmdt(m_shm);

       
    return 0;
}
