// ��֤���ö��������Դ

#include <iostream>

using namespace std;

int main()
{
	double     d = 1.0;		// dΪdouble�ͣ�ֵΪ1.0��
	const int& p = 5;		// p���ó�����
	const int& q = d;		// q����double�ͣ�

	const_cast<int&>(q) = 3.14;		// ��3.14����int����double��

	cout << "d = " << d << '\n';
	cout << "p = " << p << '\n';
	cout << "q = " << q << '\n';
}
