// ������Ԫ���������У������棩

#include <iostream>

using namespace std;

//--- ��Ԫ�ظ���Ϊn������a�������� ---//
void reverse(int a[], int n)
{
	for (int i = 0; i < n / 2; i++) {
		int t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
	}
}

int main()
{
	const int n = 5;				// ����c��Ԫ�ظ���
	int c[n];

	for (int i = 0; i < n; i++) {	// �Ը�Ԫ�ض���ֵ
		cout << "c[" << i << "] : ";
		cin >> c[i];
	}
	reverse(c, n);					// ������c��Ԫ����������

	cout << "��Ԫ���������С�\n";
	for (int i = 0; i < n; i++)		// ��ʾ����c
		cout << "c[" << i << "] = " << c[i] << '\n';
}
