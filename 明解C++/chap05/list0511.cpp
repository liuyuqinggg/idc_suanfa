// 2��3�е�����ļӷ�

#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	int a[2][3] = { {1, 2, 3}, {4, 5, 6} };
	int b[2][3] = { {6, 3, 4}, {5, 1, 2} };
	int c[2][3];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			c[i][j] = a[i][j] + b[i][j];

	cout << "����a\n";					// ��ʾ����a�Ĺ���Ԫ�ص�ֵ
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
			cout << setw(3) << a[i][j];
		cout << '\n';
	}

	cout << "����b\n";					// ��ʾ����b�Ĺ���Ԫ�ص�ֵ
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
			cout << setw(3) << b[i][j];
		cout << '\n';
	}

	cout << "����c\n";					// ��ʾ����c�Ĺ���Ԫ�ص�ֵ
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
			cout << setw(3) << c[i][j];
		cout << '\n';
	}
}
