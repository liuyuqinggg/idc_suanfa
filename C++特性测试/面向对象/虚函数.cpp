#include <iostream>
#include <memory>
using namespace std;
 
 
typedef void (*func)(void);

class A {
public:
	void f() { cout << "A::f" << endl; }
	void g() { cout << "A::g" << endl; }
	void h() { cout << "A::h" << endl; }
};

class Base {
public:
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
};

class Derive: public Base {
public:
	void f() { cout << "Derive::f" << endl; }
    void g() { cout << "Derive::g" << endl; }
	void h() { cout << "Derive::h" << endl; }
};
 
int main() 
{
	Base base;
    Derive derive;
	//获取vptr的地址，运行在gcc  x64环境下，所以将指针按unsigned long *大小处理
    //另外基于C++的编译器应该是保证虚函数表的指针存在于对象实例中最前面的位置
	unsigned long* vPtr = (unsigned long*)(&base);
	//获取vTable 首个函数的地址
	func vTable_f = (func)*(unsigned long*)(*vPtr);
	//获取vTable 第二个函数的地址
	func vTable_g = (func)*((unsigned long*)(*vPtr) + 1);//加1 ，按步进计算
	func vTable_h = (func)*((unsigned long*)(*vPtr) + 2);//同上
	vTable_f();
	vTable_g();
	vTable_h();
    vPtr = (unsigned long*)(&derive);
	//获取vTable 首个函数的地址
	vTable_f = (func)*(unsigned long*)(*vPtr);
	//获取vTable 第二个函数的地址
	vTable_g = (func)*((unsigned long*)(*vPtr) + 1);//加1 ，按步进计算
	vTable_h = (func)*((unsigned long*)(*vPtr) + 2);//同上
	vTable_f();
	vTable_g();
	vTable_h();
    cout<<sizeof(A)<<endl;
    cout<<sizeof(base)<<endl;
    cout<<sizeof(derive)<<endl;
	return 0;
}
/*
Base::f
Base::g
Base::h
Derive::f
Derive::g
Derive::h
1
8
8
*/

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vwcp3h/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。