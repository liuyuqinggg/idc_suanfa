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

struct st_stcode
{
    char provname[31]; //省
    char obtid[11]; //站号
    char obtname[31];
    double lat;
    double lon;
    double height;
};

vector<st_stcode> vstcode;

bool LoadSTCode(const char *inifile);


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
    

    if(!LoadSTCode(argv[1])){
        return -1;
    }
    

    logfile.Write("crtsurfdata1 运行结束。\n");

    return 0;
}

bool LoadSTCode(const char *inifile){

    CFile cfile;
    if(!cfile.Open(inifile,"r")){
        logfile.Write("cfile.Open(%s) failed.\n",inifile);
    }

    char strBuffer[301];

    struct st_stcode stcode;

    CCmdStr cmdStr;

   

    while (true)
    {

        //读取一行
        if(!cfile.Fgets(strBuffer,300,true)) break;
        
        //拆分
        cmdStr.SplitToCmd(strBuffer,",",true);

        if(cmdStr.CmdCount() != 6) continue;

        //写入结构体
        cmdStr.GetValue(0,stcode.provname,30);
        cmdStr.GetValue(1,stcode.obtid,10);
        cmdStr.GetValue(2,stcode.obtname,30);
        cmdStr.GetValue(3,&stcode.lat);
        cmdStr.GetValue(4,&stcode.lon);
        cmdStr.GetValue(5,&stcode.height);


        //加入vector
        vstcode.push_back(stcode);

    }

    for (int i = 0; i < vstcode.size(); i++)
    {
        logfile.Write("provname=%s,obtid=%s,obtname=%s,lat=%.2f,lon=%.2f,height=%.2f\n",
                            vstcode[i].provname, vstcode[i].obtid, vstcode[i].obtname,
                            vstcode[i].lat, vstcode[i].lon, vstcode[i].height);
    }
    
    return true;


}
