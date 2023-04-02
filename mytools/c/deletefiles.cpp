#include "_public.h"

void EXIT(int sig){
    printf("exit,sig=%d\n\n",sig);
    exit(0);
}

int main(int argc, char const *argv[])
{
    //help info
    // printf("%d\n",argc);

    if(argc != 4){
        printf("Using:/project/tools/bin/deletefiles pathname matchstr timeout");
        printf("Examples: /home/lyq/project/mytools/bin/deletefiles /home/lyq/project/tem/surfdata \"*.xml,*.json\" 0.01\n" );
        printf("       /home/lyq/project/mytools/bin/deletefiles /tmp/idc/surfdata \"*.xml,*.json\" 0.01\n" );
        printf("       /home/lyq/project/mytools/bin/procctl 300 /home/lyq/project/mytools/bin/deletefiles /log/idc \"*.log.20*\" 0.02\n" );
        printf("       /home/lyq/project/mytools/bin/procctl 300 /home/lyq/project/mytools/bin/deletefiles /tmp/idc/surfdata \"*.xml,*.json\" 0.01\n" );

        printf("这是一个工具程序，用于删除历史的数据文件和日志文件\n");
        printf("本程序把pathname目录及其子目录中timeout天之前匹配matchstr文件全部删除，timeout可以是小数\n");
        printf("本程序不写日志文件，也不会在控制台输出如何信息\n");
        // printf("本程序调用/usr/bin/gzip命令压缩文件\n");
    }
    

    //close all signal and io
    // CloseIOAndSignal(true);

    //get timeout
    char strTimeOut[21];
    LocalTime(strTimeOut,"yyyy-mm-dd hh24:mi:ss",0 - (int)stof(argv[3])*24*60*60); //研究一下LocalTime

    //open directory
    CDir Dir;
    if(Dir.OpenDir(argv[1],argv[2],10000,true) == false){
        printf("Dir.OpenDir(%s) failed\n",argv[1]); return -1;
    }

    //traversal directory
    while(true){
        if(Dir.ReadDir() == false) break;
        // printf("FullFileName=%s\n",Dir.m_FullFileName);

        //check file whether if timeout
        if(strcmp(Dir.m_ModifyTime,strTimeOut) < 0){
          
            if(REMOVE(Dir.m_FullFileName) == true){
                printf("remove %s ok.\n",Dir.m_FullFileName);
            }else{
                printf("remove %s failed.\n",Dir.m_FullFileName);
            }
        }
    }


    return 0;
}
