// ������������ֵ�ĺ���

#include <iostream>

using namespace std;

//--- ��������x��y��ֵ ---//
void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

int main()
{
	int a, b;

	cout << "����a��";   cin >> a;
	cout << "����b��";   cin >> b;

	swap(a, b);			// ����a��b��

	cout << "��������a��b��ֵ��\n";
	cout << "����a��ֵΪ" << a << "��\n";
	cout << "����b��ֵΪ" << b << "��\n";
}
