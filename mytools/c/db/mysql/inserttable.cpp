#include "_mysql.h"

// 定义用于超女信息的结构，与表中的字段对应。
struct st_girls
{
  long id;        // 超女编号，用long数据类型对应Oracle无小数的number(10)。
  char name[31];  // 超女姓名，用char[31]对应Oracle的varchar2(30)。
  double weight;  // 超女体重，用double数据类型对应Oracle有小数的number(8,2)。
  char btime[20]; // 报名时间，用char对应Oracle的date，格式：'yyyy-mm-dd hh24:mi:ssi'。
} stgirls;

int main(int argc, char const *argv[])
{
    connection conn;

    if(conn.connecttodb("127.0.0.1,root,mysql,mysql,3306","utf8") != 0){
        printf("connect database failed.\n%s\n",conn.m_cda.message); return -1;
    }
    printf("connect database ok.\n%s\n",conn.m_cda.message); 

    sqlstatement stmt(&conn);

    // prepare方法不需要判断返回值。用 ？ 代替 ：1，：2 也可以
    stmt.prepare("insert into girls(id , name ,\
 weight , btime ) \
 values(:1,:2,:3,str_to_date(:4,'%%Y-%%m-%%d %%H:%%i:%%s'))");

    printf("%s\n",stmt.m_sql);
   // 也可以用以下一行代码代替上面这行代码，兼容oracle数据库。
    //            values(:1,:2,:3,to_date(:4,'yyyy-mm-dd hh24:mi:ss'))");

    stmt.bindin(1,&stgirls.id);
    stmt.bindin(2,stgirls.name,30);
    stmt.bindin(3,&stgirls.weight);
    stmt.bindin(4,stgirls.btime,19);

    
    // 模拟超女数据，向表中插入5条测试信息。
    for (int ii=1;ii<=5;ii++)
    {
        memset(&stgirls,0,sizeof(stgirls)); // 结构体变量初始化。

        // 为结构体变量的成员赋值。
        stgirls.id=ii;                                 // 超女编号。
        sprintf(stgirls.name,"超女%02dabcde",ii);           // 超女姓名。
        stgirls.weight=ii*2.11;                        // 超女体重。
        strcpy(stgirls.btime,"2018-03-01 12:25:31");   // 报名时间。

        // 执行SQL语句，一定要判断返回值，0-成功，其它-失败。
        // 失败代码在stmt.m_cda.rc中，失败描述在stmt.m_cda.message中。
        if (stmt.execute() != 0)
        {
            printf("stmt.execute() failed.\n%s\n%d\n%s\n",stmt.m_sql,stmt.m_cda.rc,stmt.m_cda.message); return -1;
        }

        printf("成功插入了%ld条记录。\n",stmt.m_cda.rpc); // stmt.m_cda.rpc是本次执行SQL影响的记录数。
    }

    printf("insert table girls ok.\n");

    conn.commit(); // 提交数据库事务。

    return 0;
}


