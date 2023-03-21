#include <iostream>

using namespace std;

class A {
private:
    int val;
public:
    ~A() {
        cout<<"A destroy!"<<endl;
    }
};

class B: public  A {
private:
    int *arr;
public:
    B() {
        arr = new int[10];
    }
    ~B() {
        cout<<"B destroy!"<<endl;
        delete arr;
    }
};

int main() {
    A *base = new B();
    delete base;
    return 0;
}
// A destroy!

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vwfy77/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。