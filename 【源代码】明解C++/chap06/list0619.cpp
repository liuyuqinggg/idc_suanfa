// ������������������ֵ

#include <iostream>

using namespace std;

//--- ��������x��y��ֵ ---//
void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

//--- ���������в���a��b��c ---//
void sort(int& a, int& b, int& c)
{
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
}

int main()
{
	int a, b, c;

	cout << "����a��";   cin >> a;
	cout << "����b��";   cin >> b;
	cout << "����c��";   cin >> c;

	sort(a, b, c);			// ����������a��b��c

	cout << "�������������б���a��b��c��\n";
	cout << "����a��ֵΪ" << a << "��\n";
	cout << "����b��ֵΪ" << b << "��\n";
	cout << "����c��ֵΪ" << c << "��\n";
}
