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
