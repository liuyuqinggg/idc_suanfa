// ��ʾ��ά�����Ԫ�ظ����͹���Ԫ�ظ���

#include <iostream>

using namespace std;

int main()
{
	int a[4][3];

	cout << "����aΪ"	 << sizeof(a)    / sizeof(a[0])    << "��"
						 << sizeof(a[0]) / sizeof(a[0][0]) << "�С�\n";

	cout << "����Ԫ����" << sizeof(a)    / sizeof(a[0][0]) << "����\n";
}
