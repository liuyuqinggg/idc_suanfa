// ������ĸ�Ԫ�س�ʼ��Ϊ1��2��3��4��5����ʾ

#include <iostream>

using namespace std;

int main()
{
	int a[5] = {1, 2, 3, 4, 5};	// Ԫ������Ϊint����Ԫ�ظ���Ϊ5������

	for (int i = 0; i < 5; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';
}
