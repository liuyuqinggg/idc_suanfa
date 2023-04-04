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
        printf("Using:/project/tools/bin/gzipfiles pathname matchstr timeout");
        printf("Examples: /home/lyq/project/mytools/bin/gzipfiles /home/lyq/project/tem/surfdata \"*.xml,*.json\" 0.01\n" );
        printf("       /home/lyq/project/mytools/bin/gzipfiles /tmp/idc/surfdata \"*.xml,*.json\" 0.01\n" );
        printf("       /home/lyq/project/mytools/bin/procctl 300 /home/lyq/project/mytools/bin/gzipfiles /log/idc \"*.log.20*\" 0.02\n" );
        printf("       /home/lyq/project/mytools/bin/procctl 300 /home/lyq/project/mytools/bin/gzipfiles /tmp/idc/surfdata \"*.xml,*.json\" 0.01\n" );

        printf("这是一个工具程序，用于压缩历史的数据文件和日志文件\n");
        printf("本程序把pathname目录及其子目录中timeout天之前匹配matchstr文件全部压缩，timeout可以是小数\n");
        printf("本程序不写日志文件，也不会在控制台输出如何信息\n");
        printf("本程序调用/usr/bin/gzip命令压缩文件\n");
    }
    

    //close all signal and io
    // CloseIOAndSignal(true);

    //get timeout
    char strTimeOut[21];
    LocalTime(strTimeOut,"yyyy-mm-dd hh24:mi:ss",0 - (int)(stof(argv[3])*24*60*60)); //研究一下LocalTime

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
        if(strcmp(Dir.m_ModifyTime,strTimeOut) < 0 && MatchStr(Dir.m_FileName,"*.gz") == false){
            char strCmd[1024];
            SNPRINTF(strCmd,sizeof(strCmd),1000,"/usr/bin/gzip -f %s 1>/dev/null 2>/dev/null",Dir.m_FullFileName);
            // cout << strCmd << endl;
            if(system(strCmd) == 0){
                printf("gzip %s ok.\n",Dir.m_FullFileName);
            }else{
                printf("gzip %s failed.\n",Dir.m_FullFileName);
            }
        }
    }


    return 0;
}
