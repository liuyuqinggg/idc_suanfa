// ���Ʋ���ʾ���������Ԫ��

#include <iostream>

using namespace std;

int main()
{
	const int n = 5;	// ����a��b��Ԫ�ظ���
	int a[n];			// ԭ����
	int b[n] = {0};		// Ŀ�����飨������Ԫ�س�ʼ��Ϊ0��

	for (int i = 0; i < n; i++) {	// ������a��Ԫ�ض���ֵ
		cout << "a[" << i << "] : ";
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)		// ������a������Ԫ�ظ���������b
		b[i] = a[i];

	for (int i = 0; i < n; i++)		// ��ʾ����b������Ԫ�ص�ֵ
		cout << "b[" << i << "] = " << b[i] << '\n';
}
