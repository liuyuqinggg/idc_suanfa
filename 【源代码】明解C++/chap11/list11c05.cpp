// ʹ��#ifָ��ע�ͳ���

#include <iostream>

using namespace std;

#define DEBUG	0

int main()
{
	int a = 5;
	int x = 7;

#if DEBUG == 1
	a = x;				// ��x����a
#endif

	cout << "a��ֵΪ" << a << "��\n";
}
