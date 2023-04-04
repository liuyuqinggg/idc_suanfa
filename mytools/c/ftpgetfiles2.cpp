#include "_ftp.h"

CLogFile logfile;

Cftp ftp;

struct st_arg{
    char host[31];
    int mode;
    char username[31];
    char password[31];
    char remotepath[301];
    char localpath[301];
    char matchname[101];
    char listfilename[301];
};

struct st_fileinfo{
    char filename[301];
    char mtime[21];
};

vector<struct st_fileinfo> vfileinfo;

struct st_arg starg;

void EXIT(int sig){
    printf("program exit. sig=%d.",sig);
    exit(0);
}

void _help();
bool _xml_to_arg(const char *xmlbuffer);
bool _ftpgetfiles();
bool _loadlistfile();

// ../bin/ftpgetfiles /home/lyq/project/log/ftpgetfile.log "<host>127.0.0.1:21</host><mode>1</mode><username>lyq</username><password>6</password><localpath>/home/lyq/project/idcdata/</localpath> <remotepath>/home/lyq/project/tem/surfdata/</remotepath><matchname>*.xml,*.csv</matchname><listfilename>/home/lyq/project/local/list.data</listfilename>"
int main(int argc, char const *argv[])
{
    if(argc != 3){
        _help();
        return -1;
    }

    //处理程序的退出信号
    // CloseIOAndSignal();
    signal(SIGINT,EXIT);
    signal(SIGTERM,EXIT);

    //打开日志文件
    if(logfile.Open(argv[1],"a+") == false){
        printf("打开日志文件失败（%s）。\n",argv[1]);
        return -1;
    }
    printf("打开日志文件成功（%s）。\n",argv[1]);

    //解析XML，得到程序运行的参数
    if(_xml_to_arg(argv[2]) == false) return -1;
    

    //登录ftp服务器
    if(ftp.login(starg.host,starg.username,starg.password,starg.mode) == false){
        // printf("ftp.login(%s,%s,%s,%d) failed!\n",starg.host,starg.username,starg.password,starg.mode);
        logfile.Write("ftp.login(%s,%s,%s,%d) failed!\n",starg.host,starg.username,starg.password,starg.mode);

        return -1;
    }
    logfile.Write("ftp.login(%s,%s,%s,%d) ok!\n",starg.host,starg.username,starg.password,starg.mode);
    // printf("ftp.login(%s,%s,%s,%d) ok!\n",starg.host,starg.username,starg.password,starg.mode);

   if(_ftpgetfiles() == false){
        logfile.Write("_ftpgetfiles() failed!\n"); return -1;
   }
   if( _loadlistfile() == false){
        logfile.Write(" _loadlistfile() failed!\n"); return -1;
   }

    //遍历容器 下载文件
    char strremotefilename[301], strlocalfilename[301];
    for (int i = 0; i < vfileinfo.size(); i++)
    {
        SNPRINTF(strremotefilename,sizeof(strremotefilename),300,"%s%s",starg.remotepath,vfileinfo[i].filename);
        SNPRINTF(strlocalfilename,sizeof(strlocalfilename),300,"%s%s",starg.localpath,vfileinfo[i].filename);
        //ftp.get()
        logfile.Write("get %s ...\n",strremotefilename);
        if(ftp.get(strremotefilename,strlocalfilename) == false){
            logfile.Write("get %s failed!\n",strremotefilename);
            break;
        }
        logfile.Write("get %s ok!\n",strremotefilename);
    }
    
    

    return 0;
}

void _help(){
    printf("\n");
        printf("Using:/home/lyq/project/mytools/bin/ftpgetfiles logfilename xmlbuffer\n\n");

        printf("Example:/home/lyq/project/mytools/bin/procctl 30 /home/lyq/project/mytools/bin/ftpgetfiles /home/lyq/project/log/ftpgetfile.log \
<host>127.0.0.1:21</host><mode>1</mode><username>lyq</username><password>6</password><localpath>/home/lyq/project/idcdata/</localpath> \
<remotepath>/home/lyq/project/tem/surfdata/</remotepath><matchname>*.xml,*.csv</matchname><listfilename>/home/lyq/project/local/list.data</listfilename>\n\n\n");
        printf("本程序是通用的功能模块，用于把远程ftp服务器的文件下载到本地目录。\n");
        printf("logfilename是本程序的日志文件名称。\n");
        printf("xmlbuffer是文件下载的参数，如下：\n");
        printf("<host>127.0.0.1:21</host> 远程服务器的IP和端口\n");
        printf("<mode>1</mode> 传输模式，1-被动模式，2-主动模式，缺省采用被动模式\n");
        printf("<username>lyq</username> ftp用户名\n");
        printf("<password>6</password> ftp密码\n");
        printf("<localpath>/home/lyq/project/local/</localpath> 本地文件存放目录\n");
        printf("<remotepath>/home/lyq/project/tem/surfdata/</remotepath> 远程服务器待下载文件存放的目录\n");
        printf("<matchname>*.xml,*.csv</matchname> 匹配规则\n");
        printf("<listfilename>/home/lyq/project/local/list.data</listfilename> 下载的服务器目录文件存在本地的文件名称\n");
}
// xmlsoft.org
bool _xml_to_arg(const char *xmlbuffer){
    memset(&starg,0,sizeof(starg));
    GetXMLBuffer(xmlbuffer,"host",starg.host,30);
    if(strlen(starg.host) == 0){
        logfile.Write("host is null.\n");
        return false;
    }
    GetXMLBuffer(xmlbuffer,"mode",&starg.mode);
    if(starg.mode != 2) starg.mode = 1;

    GetXMLBuffer(xmlbuffer,"username",starg.username,30);
    if(strlen(starg.host) == 0){
        logfile.Write("username is null.\n");
        return false;
    }
    GetXMLBuffer(xmlbuffer,"password",starg.password,30);
    if(strlen(starg.host) == 0){
        logfile.Write("password is null.\n");
        return false;
    }
    GetXMLBuffer(xmlbuffer,"remotepath",starg.remotepath,301);
    if(strlen(starg.host) == 0){
        logfile.Write("remotepath is null.\n");
        return false;
    }
    GetXMLBuffer(xmlbuffer,"localpath",starg.localpath,301);
    if(strlen(starg.host) == 0){
        logfile.Write("localpath is null.\n");
        return false;
    }
    GetXMLBuffer(xmlbuffer,"matchname",starg.matchname,101);
    if(strlen(starg.host) == 0){
        logfile.Write("matchname is null.\n");
        return false;
    }
    GetXMLBuffer(xmlbuffer,"listfilename",starg.listfilename,301);
    if(strlen(starg.host) == 0){
        logfile.Write("listfilename is null.\n");
        return false;
    }
    return true;
}

bool _ftpgetfiles(){
    //进入ftp服务器存放文件的目录
    if(ftp.chdir(starg.remotepath) == false){
        logfile.Write("ftp.chdir(%s) failed!\n",starg.remotepath);
        return false;
    }

    //调用ftp.nlist()方法列出服务器目录中的文件，把结果存放到本地
    if(ftp.nlist(".",starg.listfilename) == false){
        logfile.Write("ftp.nlist(\".\",%s) failed!\n",starg.listfilename);
        return false;
    }
    logfile.Write("ftp.nlist(\".\",%s) ok!\n",starg.listfilename);

    //把ftp.nlist()方法获取到的list文件加载到容器vfilelist中

    //遍历容器


    return true;

}

bool _loadlistfile(){
    vfileinfo.clear();

    CFile File;
    if(File.Open(starg.listfilename,"r") == false){
        logfile.Write("File.Open(%s,\"r\") failed! \n",starg.listfilename);
    }
    logfile.Write("File.Open(%s,\"r\") ok! \n",starg.listfilename);

    struct st_fileinfo stfileinfo;
    while (true)
    {
        memset(&stfileinfo,0,sizeof(stfileinfo));

        if(File.Fgets(stfileinfo.filename,300,true) == false) break;

        if(MatchStr(stfileinfo.filename,starg.matchname) == false) continue;
        vfileinfo.push_back(stfileinfo);
        
    }
    // for (int i = 0; i < vfileinfo.size(); i++)
    // {
    //     logfile.Write("%s \n",vfileinfo[i].filename);
    // }
    

    return true;
}