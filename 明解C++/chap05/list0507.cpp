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
