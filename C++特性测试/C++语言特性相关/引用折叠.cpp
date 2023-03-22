#include <iostream>
using namespace std;

typedef int&  lref;
typedef int&& rref;

void fun(int&& tmp) 
{ 
    cout << "fun rvalue bind:" << tmp << endl; 
} 

void fun(int& tmp) 
{ 
    cout << "fun lvalue bind:" << tmp << endl; 
} 

int main() 
{ 
    int n = 11; 
    fun((lref&)n);
    fun((lref&&)n);
    fun((rref&)n);
    fun((rref&&)n);
    return 0;
}
/*
fun lvalue bind:11
fun lvalue bind:11
fun lvalue bind:11
fun rvalue bind:11
*/

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vd00s1/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。