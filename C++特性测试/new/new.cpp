#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    char buf[100];
    int *p=new (buf) int(101);
    cout<<*(int*)buf<<endl;
    return 0;
}

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vwwcws/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。