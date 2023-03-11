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

struct st_surfdata{
    char obtid[11]; //站点代码
    char ddatetime[21]; //数据时间
    int t; //气温
    int p; //气压
    int u;     //相对湿度
    int wd;  //风向
    int wf; //风速
    int r; //降雨量
    int vis; //能见度
};

vector<struct st_surfdata>  vsurfdata;

char strddatetime[21];

vector<st_stcode> vstcode;

bool LoadSTCode(const char *inifile);
void CrtSurfData();
bool CrtSurfFile(const char *outpath,const char *datafmt);


int main(int argc, char const *argv[])
{
    // inifile  outpath logfile
    if(argc != 5){
        printf("Using:./crtsurfdata1 inifile outpath logfile datafmt\n");
        printf("Example:/home/lyq/project/myidc/bin/crtsurfdata5 /home/lyq/project/myidc/ini/stcode.ini /home/lyq/project/tem/surfdata\
                 /home/lyq/project/myidc/log/crtsurfdata5.log xml,json,csv\n");

        printf("inifile 全国气象站点参数文件名。\n");
        printf("outpath 全国气象站点数据文件存放的目录。\n");
        printf("logfile 本程序运行的日志文件名。\n");
        printf("datafmt 生成数据文件的格式，支持xml、json和csv三种格式，中间用逗号分隔。\n\n");


        return -1;

    }

    if(!logfile.Open(argv[3])){
        printf("logfile.Open(%s) failed.\n",argv[3]); return -1;
    }

    logfile.Write("crtsurfdata5 开始运行。\n");
    

    if(!LoadSTCode(argv[1])){
        return -1;
    }

    CrtSurfData(); //生成数据到vector  不能写成 void CrtSurfData(); 否则不执行。

    if(strstr(argv[4],"csv") != NULL){
        CrtSurfFile(argv[2],"csv");
    }

    if(strstr(argv[4],"xml") != NULL){
        CrtSurfFile(argv[2],"xml");
    }

    if(strstr(argv[4],"json") != NULL){
        CrtSurfFile(argv[2],"json");
    }
        
    

    logfile.Write("crtsurfdata5 运行结束。\n");

    return 0;
}

bool CrtSurfFile(const char *outpath,const char *datafmt){
    //拼接文件名
    CFile File;

    char strFileName[301];
    memset(strddatetime,0,sizeof(strddatetime));
    LocalTime(strddatetime,"yyyymmddhh24miss");
    sprintf(strFileName, "%s/SURF_ZH_%s_%d.%s",outpath,strddatetime,getpid(),datafmt);

    //打开文件
    if(File.OpenForRename(strFileName,"w") == false){
        logfile.Write("File.OpenForRename(%s) failed.\n",strFileName);
        return false;
    }

    //写入第一行标题
    if(strcmp(datafmt,"csv") == 0) File.Fprintf("站点代码,数据时间,气温,气压,相对湿度,风向,风速,降雨量,能见度\n");
    if(strcmp(datafmt,"xml") == 0) File.Fprintf("<data>\n");
    if(strcmp(datafmt,"json") == 0) File.Fprintf("{\"data\":[\n");

    //遍历vector写入
    for (int i = 0; i < vsurfdata.size(); i++)
    {
        if(strcmp(datafmt,"csv") == 0){
            File.Fprintf("%s,%s,%.1f,%.1f,%d,%d,%.1f,%.1f,%.1f\n",vsurfdata[i].obtid,\
            vsurfdata[i].ddatetime,vsurfdata[i].t/10.0,vsurfdata[i].p/10.0,\
            vsurfdata[i].u,vsurfdata[i].wd,vsurfdata[i].wf/10.0,vsurfdata[i].r/10.0,vsurfdata[i].vis/10.0);
        }
        if(strcmp(datafmt,"xml") == 0){
            File.Fprintf("<obtid>%s</obtid><ddatetime>%s</ddatetime><t>%.1f</t><p>%.1f</p>"\
                   "<u>%d</u><wd>%d</wd><wf>%.1f</wf><r>%.1f</r><vis>%.1f</vis><endl/>\n",\
                   vsurfdata[i].obtid, vsurfdata[i].ddatetime,vsurfdata[i].t/10.0,vsurfdata[i].p/10.0,\
                    vsurfdata[i].u,vsurfdata[i].wd,vsurfdata[i].wf/10.0,vsurfdata[i].r/10.0,vsurfdata[i].vis/10.0);
        }
        if(strcmp(datafmt,"json") == 0){
            File.Fprintf("{\"obtid\":\"%s\",\"ddatetime\":\"%s\",\"t\":\"%.1f\",\"p\":\"%.1f\","\
                   "\"u\":\"%d\",\"wd\":\"%d\",\"wf\":\"%.1f\",\"r\":\"%.1f\",\"vis\":\"%.1f\"}",\
                    vsurfdata[i].obtid, vsurfdata[i].ddatetime,vsurfdata[i].t/10.0,vsurfdata[i].p/10.0,\
                    vsurfdata[i].u,vsurfdata[i].wd,vsurfdata[i].wf/10.0,vsurfdata[i].r/10.0,vsurfdata[i].vis/10.0);
            if (i < vsurfdata.size() - 1) File.Fprintf(",\n");
            else   File.Fprintf("\n");
        }
        
    }

    if(strcmp(datafmt,"xml") == 0) File.Fprintf("</data>\n");
    if(strcmp(datafmt,"json") == 0) File.Fprintf("]}\n");
    File.CloseAndRename();
    logfile.Write("生成数据文件%s成功，数据时间%s，记录数%d。\n",strFileName,strddatetime,vsurfdata.size());
    
    return true;
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

    // for (int i = 0; i < vstcode.size(); i++)
    // {
    //     logfile.Write("provname=%s,obtid=%s,obtname=%s,lat=%.2f,lon=%.2f,height=%.2f\n",
    //                         vstcode[i].provname, vstcode[i].obtid, vstcode[i].obtname,
    //                         vstcode[i].lat, vstcode[i].lon, vstcode[i].height);
    // }
    logfile.Write("读入vstcode %d条数据\n",vstcode.size());
    return true;


}

void CrtSurfData(){
    // logfile.Write("enter CrtSurfData\n");

    //设置随机数
    srand(time(0));

    char strddatetime[21];
    memset(strddatetime,0,sizeof(strddatetime));
    LocalTime(strddatetime,"yyyymmddhh24miss");

    struct st_surfdata stsurfdata;

    for(int i = 0; i < vstcode.size(); i++){
        memset(&stsurfdata,0,sizeof(struct st_surfdata));
        strncpy(stsurfdata.obtid,vstcode[i].obtid,10);
        strncpy(stsurfdata.ddatetime,strddatetime,14);  // 数据时间：格式yyyymmddhh24miss
        stsurfdata.t=rand()%351;       // 气温：单位，0.1摄氏度
        stsurfdata.p=rand()%265+10000; // 气压：0.1百帕
        stsurfdata.u=rand()%100+1;     // 相对湿度，0-100之间的值。
        stsurfdata.wd=rand()%360;      // 风向，0-360之间的值。
        stsurfdata.wf=rand()%150;      // 风速：单位0.1m/s
        stsurfdata.r=rand()%16;        // 降雨量：0.1mm
        stsurfdata.vis=rand()%5001+100000;  // 能见度：0.1米

        vsurfdata.push_back(stsurfdata);

    }

    logfile.Write("写入vsurfdata%d条数据\n",vsurfdata.size());


}