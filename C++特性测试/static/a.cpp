#include <iostream>
using namespace std;
int g_var = 0; // 全局变量
static char *gs_var;  // 静态全局变量
extern int test();
int main()
{
    int var;                    // 局部变量
    static int s_var = 0;       // 静态局部变量
    test();  
    return 0;
}

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vwrt6c/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。