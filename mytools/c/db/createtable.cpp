#include "_mysql.h"

int main(int argc, char const *argv[])
{
    connection conn;

    if(conn.connecttodb("127.0.0.1,root,mysql,mysql,3306","utf8") != 0){
        printf("connect database failed.\n%s\n",conn.m_cda.message); return -1;
    }

    return 0;
}
