#include <iostream>
#include <memory>
using namespace std;
 
 
typedef void (*func)(void);

class Base
{
public:
    virtual void fun1() { cout << "Base::fun1()" << endl; }
    virtual void B_fun2() { cout << "Base::B_fun2()" << endl; }
    virtual void B_fun3() { cout << "Base::B_fun3()" << endl; }
};

class Derive : public Base
{
public:
    virtual void fun1() { cout << "Derive::fun1()" << endl; }
    virtual void D_fun2() { cout << "Derive::D_fun2()" << endl; }
    virtual void D_fun3() { cout << "Derive::D_fun3()" << endl; }
};

void printVtable(unsigned long *vptr, int offset) {
	func fn = (func)*((unsigned long*)(*vptr) + offset);
	fn();	
}

int main()
{
    Base *p = new Derive();
	unsigned long* vPtr = (unsigned long*)(p);
	printVtable(vPtr, 0);
	printVtable(vPtr, 1);
	printVtable(vPtr, 2);
	printVtable(vPtr, 3);
	printVtable(vPtr, 4);
    cout<<sizeof(Base)<<endl; // 8
    cout<<sizeof(Derive)<<endl; // 8
    return 0;
}

/*
Derive::fun1()
Base::B_fun2()
Base::B_fun3()
Derive::D_fun2()
Derive::D_fun3()
8
8
*/

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vwbet3/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。