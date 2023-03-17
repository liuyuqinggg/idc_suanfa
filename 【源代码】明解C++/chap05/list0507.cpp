// 显示数组及其元素的类型

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
	int a[5];
	double b[7];

	cout << "type of a " << typeid(a).name()    << '\n';	// int数组
	cout << "type of a[0] " << typeid(a[0]).name() << '\n';	// 它的元素

	cout << "type of b " << typeid(b).name()    << '\n';	// double数组
	cout << "type of b[0] " << typeid(b[0]).name() << '\n';	// 它的元素
}
