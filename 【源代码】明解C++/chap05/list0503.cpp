// �������Ԫ�ظ�ֵΪ1��2��3��4��5����ʾ��for��䣩

#include <iostream>

using namespace std;

int main()
{
	int a[5];		// int[5]�͵����飨Ԫ������Ϊint����Ԫ�ظ���Ϊ5�����飩

	for (int i = 0; i < 5; i++)
		a[i] = i + 1;

	for (int i = 0; i < 5; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';
}
