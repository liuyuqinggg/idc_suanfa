// �����1�ӵ�n�Ľ��

#include <iostream>

using namespace std;

int main()
{
	int n;

	cout << "�����1�ӵ�n�Ľ����\n";
	do {
		cout << "n��ֵ��";
		cin >> n;
	} while (n <= 0);

	int sum = 0;		// ���
	int i = 1;

	while (i <= n) {
		sum += i;		// ��sum��i
		i++;			// ����i
	}
	cout << "��1�ӵ�" << n << "�Ľ����" << sum << "��\n";
}
