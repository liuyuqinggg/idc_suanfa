#include <iostream>
#include <memory>
using namespace std;
typedef void (*func)(void);
class A
{
private:
    int a1;
    int a2;

public:
    virtual void display()
    {
        cout << "A::display()" << endl;
    }
    virtual void clone()
    {
        cout << "A::clone()" << endl;
    }
};

class B : public A
{
private:
    int b;

public:
    virtual void display()
    {
        cout << "B::display()" << endl;
    }
     virtual void init()
    {
        cout << "B::init()" << endl;
    }
};

class C : public B
{
private:
    int c;

public:
    virtual void display()
    {
        cout << "C::display()" << endl;
    }
     virtual void execute()
    {
        cout << "C::execute()" << endl;
    }
    virtual void init()
    {
        cout << "C::init()" << endl;
    }
   
};

int main()
{
    A *p1 = new B();
    A *p2 = new C();
    p1->display();

    p2->display();

    cout << "\n";

    unsigned long* vPtr = (unsigned long*)(p2);
    func vTable_1 = (func)*(unsigned long*)(*vPtr);
    func vTable_2 = (func)*((unsigned long*)(*vPtr)+1);
    func vTable_3 = (func)*((unsigned long*)(*vPtr) + 2);
    func vTable_4 = (func)*((unsigned long*)(*vPtr) + 3);
    vTable_1();
    vTable_2();
    vTable_3();
    vTable_4();

    
    return 0;
}

// 作者：小老鼠的大梦想
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vd21fs/?discussion=R3Fu9s
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。