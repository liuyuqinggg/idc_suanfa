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
    int ptype;
    char remotepathbak[301];
    char okfilename[301];
    bool checktime = false;
    int timeout;
    char pname[51];
};
struct st_fileinfo{
    char filename[301];
    char mtime[21];
};

vector<struct st_fileinfo> vfileinfo1; //已经下载成功文件名的容器，从okfilename中加载
vector<struct st_fileinfo> vfileinfo2; //下载前列出服务器文件名的容器，从nlist文件中加载
vector<struct st_fileinfo> vfileinfo3; //本次不需要下载的文件的容器
vector<struct st_fileinfo> vfileinfo4; //本次需要下载的文件的容器

struct st_arg starg;

void EXIT(int sig){
    printf("program exit. sig=%d.",sig);
    exit(0);
}

void _help();
bool _xml_to_arg(const char *xmlbuffer);
bool _ftpgetfiles();
bool _loadlistfile();
bool LoadOKFile();
bool CompVector();
bool WriteToOKFile();
bool AppendToOKFile(struct st_fileinfo *);

CPActive PActive;


// ../bin/ftpgetfiles /home/lyq/project/log/ftpgetfile.log "<host>127.0.0.1:21</host><mode>1</mode><username>lyq</username><password>6</password><localpath>/home/lyq/project/idcdata/</localpath> <remotepath>/home/lyq/project/tem/surfdata/</remotepath><matchname>*.xml,*.csv</matchname><listfilename>/home/lyq/project/local/list.data</listfilename><ptype>1</ptype><remotepathbak>/home/lyq/project/surfdatabak/</remotepathbak><okfilename>/home/lyq/project/idcdata/ftplist/ftpgetfiles_surdata.xml</okfilename><checktime>true</checktime><timeout>20</timeout><pname>ftpgetfile_</pname>"
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
    logfile.Write("打开日志文件成功（%s）。\n",argv[1]);

    //解析XML，得到程序运行的参数
    if(_xml_to_arg(argv[2]) == false) return -1;

    PActive.AddPInfo(starg.timeout,starg.pname,&logfile);
    // sleep(60); 模拟程序超时场景。
    

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

   if(starg.ptype == 1){

        //加载okfilename文件中的内容到容器vfileinfo1中。
        if(LoadOKFile() == false){
            return -1;
        }

        //比较vfileinfo1和vfileinfo2,得到vfileinfo3 and vfileinfo4
        if(CompVector() == false){
            return -1;
        }

        //用vfileinfo3内容写入okfilename
        if(WriteToOKFile() == false){
            return -1;
        }

        //把vfileinfo4 覆盖到 vfileinfo2，此时vfileinfo2中就是要下载的文件名集合
        vfileinfo2.clear();
        vfileinfo2.swap(vfileinfo4);

   }
    PActive.UptATime();
    //遍历容器 下载文件
    char strremotefilename[301], strlocalfilename[301];
    for (int i = 0; i < vfileinfo2.size(); i++)
    {
        SNPRINTF(strremotefilename,sizeof(strremotefilename),300,"%s%s",starg.remotepath,vfileinfo2[i].filename);
        SNPRINTF(strlocalfilename,sizeof(strlocalfilename),300,"%s%s",starg.localpath,vfileinfo2[i].filename);
        //ftp.get()
        logfile.Write("get %s ...\n",strremotefilename);
        if(ftp.get(strremotefilename,strlocalfilename) == false){
            logfile.Write("get %s failed!\n",strremotefilename);
            break;
        }
        PActive.UptATime();
        logfile.Write("get %s ok!\n",strremotefilename);

        //append the new downloaded file name to okfilename
        if(starg.ptype == 1){ 
            AppendToOKFile(&vfileinfo2[i]);
        }

        //delete file
        if(starg.ptype == 2){
            if(ftp.ftpdelete(strremotefilename) == false){
                logfile.Write("ftp.ftpdelete(%s) failed\n",strremotefilename);
                return false;
            }
        }

        //restore file
        if(starg.ptype == 3){
            char strremotefilebakname[301];
            SNPRINTF(strremotefilebakname,sizeof(strremotefilebakname),300,"%s/%s",starg.remotepathbak,vfileinfo2[i].filename);
            if(ftp.ftprename(strremotefilename,strremotefilebakname) == false){
                logfile.Write("ftp.ftprename(%s,%s) failed\n",strremotefilename,strremotefilebakname);
                return false;
            }
        }

    }

    return 0;
}

bool AppendToOKFile(struct st_fileinfo *stfileinfo){
    CFile File;
    if(File.Open(starg.okfilename,"a") == false){
        logfile.Write("File.Open(%s,\"w\") failed!\n",starg.okfilename);
        return false;
    }

    File.Fprintf("<filename>%s</filename><mtime>%s</mtime>\n",stfileinfo->filename,stfileinfo->mtime);
    return true;
}

bool LoadOKFile(){
    vfileinfo1.clear();
    CFile File;
    //注意：如果程序第一次下载，okfilename是不存在的，并不是错误，所以返回true
    if(File.Open(starg.okfilename,"r") == false) return true;
    struct st_fileinfo stfileinfo;
    char strbuffer[501];

    while (true)
    {
        memset(&stfileinfo,0,sizeof(stfileinfo));

        if(File.Fgets(strbuffer,300,true) == false) break;
        GetXMLBuffer(strbuffer,"filename",stfileinfo.filename);
        GetXMLBuffer(strbuffer,"mtime",stfileinfo.mtime);

        vfileinfo1.push_back(stfileinfo);
        
    }
    return true;
}

bool CompVector(){

    vfileinfo3.clear();
    vfileinfo4.clear();

    for (int i = 0; i < vfileinfo2.size(); i++)
    {
        int j = 0;
        for (; j < vfileinfo1.size(); j++)
        {
            if(strcmp(vfileinfo2[i].filename,vfileinfo1[j].filename) == 0 &&
                strcmp(vfileinfo2[i].mtime,vfileinfo1[j].mtime) == 0){ // 名词和时间都相等
                vfileinfo3.push_back(vfileinfo2[i]);
                break;
            }
        }
        if(j == vfileinfo1.size()){
            vfileinfo4.push_back(vfileinfo2[i]);
        }
        
    }
    return true;

}
bool WriteToOKFile(){
    CFile File;
    if(File.Open(starg.okfilename,"w") == false){
        logfile.Write("File.Open(%s,\"w\") failed!\n",starg.okfilename);
        return false;
    }

    for (int i = 0; i < vfileinfo3.size(); i++)
    {
        File.Fprintf("<filename>%s</filename><mtime>%s</mtime>\n",vfileinfo3[i].filename,vfileinfo3[i].mtime);
    }
    return true;
    
}

void _help(){
    printf("\n");
        printf("Using:/home/lyq/project/mytools/bin/ftpgetfiles logfilename xmlbuffer\n\n");

        printf("Example:/home/lyq/project/mytools/bin/procctl 30 /home/lyq/project/mytools/bin/ftpgetfiles /home/lyq/project/log/ftpgetfile.log \
\"<host>127.0.0.1:21</host><mode>1</mode><username>lyq</username><password>6</password><localpath>/home/lyq/project/idcdata/</localpath> \
<remotepath>/home/lyq/project/tem/surfdata/</remotepath><matchname>*.xml,*.csv</matchname><listfilename>/home/lyq/project/local/list.data</listfilename> \
<ptype>1</ptype><remotepathbak>/home/lyq/project/surfdatabak/</remotepathbak><okfilename>/home/lyq/project/idcdata/ftplist/ftpgetfiles_surdata.xml</okfilename> \
<checktime>true</checktime><timeout>20</timeout><pname>ftpgetfile_</pname>\"\n\n\n");
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
        printf("<ptype>1</ptype> 文件下载成功后，远程服务器文件的处理方式:1-什么也不做； 2-删除； 3-备份，如果为3还要指定备份的目录\n");
        printf("<okfilename>/home/lyq/project/idcdata/ftplist/ftpgetfiles_surdata.xml</okfilename> 已下载成功文件名称清单，次参数只有当ptype=1时候才有效\n");
        printf("<checktime>true</checktime> 是否下载已更新的文件\n");
        printf("<timeout>20</timeout> 超时时间\n");
        printf("<pname>ftpgetfile_</pname> 进程名称\n");
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
    GetXMLBuffer(xmlbuffer,"ptype",&starg.ptype);
    if(starg.ptype != 1 && starg.ptype != 2 && starg.ptype != 3){
        logfile.Write("ptype is illegal.\n");
        return false;
    }

    GetXMLBuffer(xmlbuffer,"remotepathbak",starg.remotepathbak,301);
    if(starg.ptype == 3 && (strlen(starg.remotepathbak) == 0)){
        logfile.Write("remotepathbak is null.\n");
        return false;
    }

    GetXMLBuffer(xmlbuffer,"okfilename",starg.okfilename,301);
    if(starg.ptype == 1 && (strlen(starg.okfilename) == 0)){
        logfile.Write("okfilename is null.\n");
        return false;
    }

    GetXMLBuffer(xmlbuffer,"timeout",&starg.timeout);
    if(starg.timeout == 0){
        logfile.Write("timeout is illegal.\n");
        return false;
    }

    GetXMLBuffer(xmlbuffer,"pname",starg.pname,50);
    if(starg.ptype == 1 && (strlen(starg.pname) == 0)){
        logfile.Write("pname is null.\n");
        return false;
    }

    GetXMLBuffer(xmlbuffer,"checktime",&starg.checktime);




    return true;
}

bool _ftpgetfiles(){
    //进入ftp服务器存放文件的目录
    if(ftp.chdir(starg.remotepath) == false){
        logfile.Write("ftp.chdir(%s) failed!\n",starg.remotepath);
        return false;
    }
    PActive.UptATime();
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
    vfileinfo2.clear();
    PActive.UptATime();
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

        if(starg.ptype == 1 && starg.checktime == true){
            if(ftp.mtime(stfileinfo.filename) == false){
                logfile.Write("ftp.mtime(%s) failed! \n",stfileinfo.filename);
                return false;
            }

            strcpy(stfileinfo.mtime,ftp.m_mtime);
        }

        vfileinfo2.push_back(stfileinfo);
        
    }
    // for (int i = 0; i < vfileinfo2.size(); i++)
    // {
    //     logfile.Write("%s \n",vfileinfo2[i].filename);
    // }
    

    return true;
}