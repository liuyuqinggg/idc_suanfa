// ��ʾ�������������ֵ�н�С��ֵ������������������

#include <iostream>

using namespace std;

int main()
{
	int a, b;

	cout << "����a��";   cin >> a;
	cout << "����b��";   cin >> b;

	int min = a < b ? a : b;		// ��Сֵ

	cout << "��СֵΪ" << min << "��\n";
}
