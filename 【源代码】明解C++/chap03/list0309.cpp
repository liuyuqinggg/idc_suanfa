// ����������ֵ��������ʾ

#include <iostream>

using namespace std;

int main()
{
	int x;

	cout << "������ʾ������ֵ��\n";
	do {
		cout << "������ֵ��";
		cin >> x;
	} while (x <= 0);

	cout << "������ʾ���Ϊ";
	while (x > 0) {
		cout << x % 10;			// ��ʾx�����һλ��
		x /= 10;				// x����10
	}
	cout << "��\n";
}
