// ����������IntArray����1�棩��ʹ������

#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
	int n;

	cout << "������Ԫ�ظ�����";
	cin >> n;

	IntArray x(n);	// Ԫ�ظ���Ϊn������

	for (int i = 0; i < x.size(); i++)					// �Ը���Ԫ�ظ�ֵ
		x[i] = i;

	for (int i = 0; i < x.size(); i++)					// ��ʾ����Ԫ�ص�ֵ
		cout << "x[" << i << "] = " << x[i] << '\n';
}
