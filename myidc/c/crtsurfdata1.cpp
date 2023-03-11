/**
 * @file crtsurfdata1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "_public.h"

CLogFile logfile(10);

int main(int argc, char const *argv[])
{
    // inifile  outpath logfile
    if(argc != 4){
        printf("Using:./crtsurfdata1 inifile outpath logfile\n");
        printf("Example:/home/lyq/project/myidc/bin/crtsurfdata1 /home/lyq/project/myidc/ini/stcode.ini /home/lyq/tem/surfdata /home/lyq/myidc/log/crtsurfdata1.log\n");

        printf("inifile 全国气象站点参数文件名。\n");
        printf("outpath 全国气象站点数据文件存放的目录。\n");
        printf("logfile 本程序运行的日志文件名。\n\n");

        return -1;

    }

    if(!logfile.Open(argv[3])){
        printf("logfile.Open(%s) failed.\n",argv[3]); return -1;
    }

    logfile.Write("crtsurfdata1 开始运行。\n");
    for (int i = 0; i < 10000000; i++)
    {
        logfile.Write("这是第%ld条日志\n",i);
    }
    

    logfile.Write("crtsurfdata1 运行结束。\n");

    return 0;
}
