// ��ʾ��ά���鼰��Ԫ�ص�����

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
	int a[5][3];		// ��ά����
	double b[4][2][3];	// ��ά����

	cout << "����a�����ͣ�" << typeid(a).name()    << '\n';
	cout << "a��Ԫ�����ͣ�" << typeid(a[0]).name() << '\n';
	cout << "����b�����ͣ�" << typeid(b).name()    << '\n';
	cout << "b��Ԫ�����ͣ�" << typeid(b[0]).name() << '\n';
}
