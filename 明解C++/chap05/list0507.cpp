<<<<<<< HEAD:銆愭簮浠ｇ爜銆戞槑瑙++/chap05/list0507.cpp
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
=======
// 显示数组及其元素的类型

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
	int a[5];
	double b[7];

	cout << "数组a的类型：" << typeid(a).name()    << '\n';	// int数组
	cout << "a的元素类型：" << typeid(a[0]).name() << '\n';	// 它的元素

	cout << "数组b的类型：" << typeid(b).name()    << '\n';	// double数组
	cout << "b的元素类型：" << typeid(b[0]).name() << '\n';	// 它的元素
}
>>>>>>> b274cc34791ed0386873647df97f520c9ba42f8d:鏄庤ВC++/chap05/list0507.cpp
