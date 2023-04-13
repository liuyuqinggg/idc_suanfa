#include "_mysql.h"

int main(int argc, char const *argv[])
{
    connection conn;  

    if(conn.connecttodb("127.0.0.1,root,mysql,mysql,3306","utf8") != 0){
        printf("connect database failed.\n%s\n",conn.m_cda.message); return -1;
    }
    printf("connect database ok.\n%s\n",conn.m_cda.message); 

    sqlstatement stmt(&conn);

    // prepare方法不需要判断返回值。
    stmt.prepare("create table girls(id bigint(10), name varchar(10),\
 weight decimal(8,2), btime datetime, memo longtext,\
 pic longblob, primary key(id))");

    // 执行SQL语句，一定要判断返回值，0-成功，其它-失败。
    // 失败代码在stmt.m_cda.rc中，失败描述在stmt.m_cda.message中。
    if(stmt.execute() != 0){
        printf("stmt.execute() failed.\n%s\n%d\n%s\n",stmt.m_sql,stmt.m_cda.rc,stmt.m_cda.message); return -1;
    }

    printf("create table girls ok.\n");

    return 0;
}


