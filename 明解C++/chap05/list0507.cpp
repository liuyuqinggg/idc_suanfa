<<<<<<< HEAD:【源代码】明解C++/chap05/list0507.cpp
// ��ʾ���鼰��Ԫ�ص�����

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
	int a[5];
	double b[7];

	cout << "type of a " << typeid(a).name()    << '\n';	// int����
	cout << "type of a[0] " << typeid(a[0]).name() << '\n';	// ����Ԫ��

	cout << "type of b " << typeid(b).name()    << '\n';	// double����
	cout << "type of b[0] " << typeid(b[0]).name() << '\n';	// ����Ԫ��
}
=======
// ��ʾ���鼰��Ԫ�ص�����

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
	int a[5];
	double b[7];

	cout << "����a�����ͣ�" << typeid(a).name()    << '\n';	// int����
	cout << "a��Ԫ�����ͣ�" << typeid(a[0]).name() << '\n';	// ����Ԫ��

	cout << "����b�����ͣ�" << typeid(b).name()    << '\n';	// double����
	cout << "b��Ԫ�����ͣ�" << typeid(b[0]).name() << '\n';	// ����Ԫ��
}
>>>>>>> b274cc34791ed0386873647df97f520c9ba42f8d:明解C++/chap05/list0507.cpp
