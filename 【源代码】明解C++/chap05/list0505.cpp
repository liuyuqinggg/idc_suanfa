// ������ĸ�Ԫ�س�ʼ��Ϊ1��2��3��4��5����ʾ��ͨ��������Ԫ�ظ�����

#include <iostream>

using namespace std;

int main()
{
	int a[] = {1, 2, 3, 4, 5};
	int a_size = sizeof(a) / sizeof(a[0]);	// ����a��Ԫ�ظ���

	for (int i = 0; i < a_size; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';
}
