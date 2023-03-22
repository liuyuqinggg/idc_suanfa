#include <iostream>
using namespace std;

int g_val = 10;

void ProcessValue(int &i) {                         // 左值引用
    cout << "lValue processed: " << i << endl;
}

void ProcessValue(int &&i) {                        // 右值引用
    cout << "rValue processed: " << i << endl;
}

int GetValue() { // 返回右值
    return 3; 
} 

int& getVal() { // 返回左值引用
    return g_val; 
}

int main() {
    int a = 0;
    int b = 1;
    int &alRef = a;             // 左值引用
    int &&rRef1 = 1;            // 临时对象是右值
    int &&rRef2 = GetValue();   // 调用的函数为右值
    ProcessValue(a);            // 左值
    ProcessValue(getVal());     // 左值引用
    ProcessValue(1);            // 临时对象是右值
    ProcessValue(GetValue());   // 调用的函数为右值
    ProcessValue(a+b);          // 表达式为右值
    return 0;
}
/*
lValue processed: 0
lValue processed: 10
rValue processed: 1
rValue processed: 3
rValue processed: 1
*/

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vd00s1/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。