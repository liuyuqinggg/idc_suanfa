#include <iostream>
#include <string.h>

using namespace std;

class A{
public:
	int x;
	A(){
		memset(this, 0, sizeof(x));       // 将this对象中的成员初始化为0
		cout << "构造函数" << endl;
	}
	A(const A& a) {
		memcpy(this, &a, sizeof(A));      // 直接拷贝内存中的内容
		cout << "拷贝构造函数" << endl;
	}
	virtual void virfunc() {
		cout << "虚函数func" << endl;
	}
	void func() {
		cout << "func函数" << endl;
	}
	virtual ~A() {
		cout << "析构函数" << endl;
	}
};

int main()
{
	// A a;
	// a.virfunc(); // 静态联编  https://cloud.tencent.com/developer/article/1599283

    A *a = new A;
	a->virfunc();  // 动态联编
	return 0;
}