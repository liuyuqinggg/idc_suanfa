#include <iostream>
using namespace std;

class Base1
{
public:
    virtual void fun1() { cout << "Base1::fun1()" << endl; }
    virtual void B1_fun2() { cout << "Base1::B1_fun2()" << endl; }
    virtual void B1_fun3() { cout << "Base1::B1_fun3()" << endl; }
};
class Base2
{
public:
    virtual void fun1() { cout << "Base2::fun1()" << endl; }
    virtual void B2_fun2() { cout << "Base2::B2_fun2()" << endl; }
    virtual void B2_fun3() { cout << "Base2::B2_fun3()" << endl; }
};
class Base3
{
public:
    virtual void fun1() { cout << "Base3::fun1()" << endl; }
    virtual void B3_fun2() { cout << "Base3::B3_fun2()" << endl; }
    virtual void B3_fun3() { cout << "Base3::B3_fun3()" << endl; }
};

class Derive : public Base1, public Base2, public Base3
{
public:
    virtual void fun1() { cout << "Derive::fun1()" << endl; }
    virtual void D_fun2() { cout << "Derive::D_fun2()" << endl; }
    virtual void D_fun3() { cout << "Derive::D_fun3()" << endl; }
};

typedef void (*func)(void);

void printVtable(unsigned long *vptr, int offset) {
	func fn = (func)*((unsigned long*)(*vptr) + offset);
	fn();	
}

int main(){
    Base1 *p1 = new Derive();
    Base2 *p2 = new Derive();
    Base3 *p3 = new Derive();
    p1->fun1(); // Derive::fun1()
    p2->fun1(); // Derive::fun1()
    p3->fun1(); // Derive::fun1()
    unsigned long* vPtr = (unsigned long*)(p1);
	printVtable(vPtr, 0);
	printVtable(vPtr, 1);
	printVtable(vPtr, 2);
	printVtable(vPtr, 3);
	printVtable(vPtr, 4);
	vPtr++;
	printVtable(vPtr, 0);
	printVtable(vPtr, 1);
	printVtable(vPtr, 2);
	vPtr++;
	printVtable(vPtr, 0);
	printVtable(vPtr, 1);
	printVtable(vPtr, 2);
    cout<<sizeof(Base1)<<endl; // 8
	cout<<sizeof(Base2)<<endl; // 8
	cout<<sizeof(Base3)<<endl; // 8
    cout<<sizeof(Derive)<<endl; // 8
    return 0;
}

/*
Derive::fun1()
Derive::fun1()
Derive::fun1()
Derive::fun1()
Base1::B1_fun2()
Base1::B1_fun3()
Derive::D_fun2()
Derive::D_fun3()
Derive::fun1()
Base2::B2_fun2()
Base2::B2_fun3()
Derive::fun1()
Base3::B3_fun2()
Base3::B3_fun3()
8
8
8
24
*/

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vwbet3/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。