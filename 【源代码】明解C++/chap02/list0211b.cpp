// ��ʾ�������������ֵ�Ĳ�

#include <iostream>

using namespace std;

int main()
{
	int a, b;

	cout << "����a��";   cin >> a;
	cout << "����b��";   cin >> b;

	cout << "��Ϊ" << (a < b ? b - a : a - b) << "��\n";
}
