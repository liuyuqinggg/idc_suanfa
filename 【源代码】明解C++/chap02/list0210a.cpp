// ��ʾ�������������ֵ�н�С��ֵ������飩

#include <iostream>

using namespace std;

int main()
{
	int a, b;

	cout << "����a��";	cin >> a;
	cout << "����b��";	cin >> b;

	int min;		// ��Сֵ
	if (a < b) {
		min = a;
	} else {
		min = b;
	}

	cout << "��СֵΪ" << min << "��\n";
}
