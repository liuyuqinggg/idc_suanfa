#include <iostream>
using namespace std;

void fun(int& tmp) 
{ 
  cout << "fun lvalue bind:" << tmp << endl; 
} 

void fun(int&& tmp) 
{ 
  cout << "fun rvalue bind:" << tmp << endl; 
} 

void fun1(int& tmp) 
{ 
  cout << "fun1 lvalue bind:" << tmp << endl; 
} 

int main() 
{ 
    int var = 11; 
    fun(12); // 右值引用
    fun(var); // 左值引用
    fun(std::move(var)); // 使用std::move转为右值引用
    fun(static_cast<int&&>(var));  // 使用static_cast转为右值引用
    fun((int&&)var); // 使用C风格强转为右值引用
    fun(std::forward<int&&>(var)); // 使用std::forwad<T&&>为右值引用
    // fun1(12); // error
    return 0;
}
/*
fun rvalue bind:12
fun lvalue bind:11
fun rvalue bind:11
fun rvalue bind:11
fun rvalue bind:11
fun rvalue bind:11
*/

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vd00s1/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。