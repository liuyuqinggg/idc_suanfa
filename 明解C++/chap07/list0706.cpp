// ��ʾ����Ԫ�صĵ�ַ

#include <iostream>

using namespace std;

int main()
{
	int a[5] = {1, 2, 3, 4, 5};
	int* p = a;		// pָ��a[0]

	for (int i = 0; i < 5; i++)			// ��ʾָ��Ԫ�ص�ָ��
		cout << "&a[" << i << "] = " << &a[i] << "  p+" << i << " = " << p + i << '\n';
}
