#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    
    char arr[10];
    int var = 0x11112222;
    cout << "Address : var " << &var << endl;
    cout << "Address : arr " << &arr << endl;
    strcpy(arr, "hello world!");
    cout << "var:" << hex << var << endl; // 将变量 var 以 16 进制输出
    cout << "arr:" << arr << endl;
    return 0;
}

/*
Address : var 0x23fe4c
Address : arr 0x23fe42
var:11002164
arr:hello world!
*/

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vwqjji/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。