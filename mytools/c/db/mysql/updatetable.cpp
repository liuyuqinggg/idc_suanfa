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

    char strbtime[20];  // 用于存放超女的报名时间。
    memset(strbtime,0,sizeof(strbtime));
    strcpy(strbtime,"2019-12-20 09:45:30");

    // 准备更新数据的SQL语句，不需要判断返回值。
    stmt.prepare("\
        update girls set btime=str_to_date(:1,'%%Y-%%m-%%d %%H:%%i:%%s') where id>=2 and id<=4");
    // 也可以用以下一行代码代替上面这行代码，兼容oracle数据库。
    //  update girls set btime=to_date(:1,'yyyy-mm-dd hh24:mi:ss') where id>=2 and id<=4");
    // prepare方法不需要判断返回值。
    // 为SQL语句绑定输入变量的地址，bindin方法不需要判断返回值。
    stmt.bindin(1,strbtime,19);
    // 如果不采用绑定输入变量的方法，把strbtime的值直接写在SQL语句中也是可以的，如下：
    /*
    stmt.prepare("\
        update girls set btime=to_date('%s','yyyy-mm-dd hh24:mi:ss') where id>=2 and id<=4",strbtime);
    */

    // 执行SQL语句，一定要判断返回值，0-成功，其它-失败。
    // 失败代码在stmt.m_cda.rc中，失败描述在stmt.m_cda.message中。
    if (stmt.execute() != 0)
    {
        printf("stmt.execute() failed.\n%s\n%s\n",stmt.m_sql,stmt.m_cda.message); return -1;
    }

    // 请注意，stmt.m_cda.rpc变量非常重要，它保存了SQL被执行后影响的记录数。
    printf("本次更新了girls表%ld条记录。\n",stmt.m_cda.rpc);

    // 提交事务
    conn.commit();
    return 0;
}


