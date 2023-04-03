#include "_ftp.h"

Cftp ftp;

// g++ -g -o ftpclient ftpclient.cpp /home/lyq/project/public/_ftp.cpp /home/lyq/project/public/_public.cpp -I/home/lyq/project/public -L/home/lyq/project/public -lftp -lm -lc
// export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/lyq/project/public/
int main(int argc, char const *argv[])
{
    if(ftp.login("127.0.0.1:21","lyq","6") == false){
        printf("ftp.login(\"127.0.0.1:21\",\"lyq\",\"6\") failed!\n");
        return -1;
    }
    printf("ftp.login(\"127.0.0.1:21\",\"lyq\",\"6\") ok!\n");

    if(ftp.mtime("/home/lyq/project/ftptest/aa") == false){
        printf("ftp.mtime(\"/home/lyq/project/ftptest/aa\" failed! \n");
        return -1;
    }
    printf("ftp.mtime(\"/home/lyq/project/ftptest/aa\" ok! mtime=%s \n",ftp.m_mtime);

    if(ftp.size("/home/lyq/project/ftptest/aa") == false){
        printf("ftp.size(\"/home/lyq/project/ftptest/aa\" failed! \n");
        return -1;
    }
    printf("ftp.size(\"/home/lyq/project/ftptest/aa\" ok! size=%d \n",ftp.m_size);

    if(ftp.nlist("/home/lyq/project/","/home/lyq/nlist.txt") == false){
        printf("ftp.nlist(\"/home/lyq/project/\",\"/home/lyq/nlist.txt\") failed!\n");
        return -1;
    }
    printf("ftp.nlist(\"/home/lyq/project/\",\"/home/lyq/nlist.txt\") ok!\n");

    if(ftp.get("/home/lyq/project/ftptest/aa","/home/lyq/aa.bak",true) == false){
        printf("ftp.get() failed!.\n");
        return -1;
    }

    printf("ftp.get() ok!.\n");

    if(ftp.put("/home/lyq/bb.bak", "/home/lyq/project/ftptest/bb",true) == false){
        printf("ftp.put() failed!.\n");
        return -1;
    }

    printf("ftp.put() ok!.\n");



    ftp.logout();
    
    return 0;
}





