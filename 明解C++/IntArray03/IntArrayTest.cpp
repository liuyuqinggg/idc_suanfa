// ����������IntArray����3�棩��ʹ������

#include <iomanip>
#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
	int n;
	cout << "a��Ԫ�ظ�����";
	cin >> n;

	IntArray a(n);		// Ԫ�ظ���Ϊn������

	for (int i = 0; i < a.size(); i++)
		a[i] = i;

	IntArray b(128);	// Ԫ�ظ���Ϊ128������
	IntArray c(256);	// Ԫ�ظ���Ϊ256������

	cout << "b��c��Ԫ�ظ�����" << b.size() << "��" << c.size();
	c = b = a;					// ��ֵ
	cout << "��Ϊ" << b.size() << "��" << c.size() << "��\n";

	IntArray d = b;				// ��ʼ��

	cout << "    a    b    c    d\n";
	cout << "---------------------\n";
	for (int i = 0; i < n; i++) {
		cout << setw(5) << a[i] << setw(5) << b[i]
			 << setw(5) << c[i] << setw(5) << d[i] << '\n';
	}
}
