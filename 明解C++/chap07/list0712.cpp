// ��0�������������Ԫ�أ���1�棩

#include <iostream>

using namespace std;

//--- ��0��������p��ǰn��Ԫ�أ���1�棩---//
void fill_zero(int* p, int n)
{
	while (n-- > 0) {
		*p = 0;		// ��0������ǰԪ��
		p++;		// �ƶ�����һ��Ԫ��
	}
}

int main()
{
	int x[5] = {1, 2, 3, 4, 5};
	int x_size = sizeof(x) / sizeof(x[0]);		// ����x��Ԫ�ظ���

	fill_zero(x, x_size);						// ��0��������x������Ԫ��

	cout << "��0����������Ԫ�ء�\n";
	for (int i = 0; i < x_size; i++)
		cout << "x[" << i << "] = " << x[i] << '\n';	// ��ʾx[i]��ֵ
}
