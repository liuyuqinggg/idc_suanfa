// �ɺ���������������ֵ�ĺ����

#include <iostream>

using namespace std;

//--- ��x��y�ĺ��������*sum��*mul ---//
void sum_mul(int x, int y, int* sum, int* mul)
{
	*sum = x + y;		// ��x��y�ĺ͸���*sum
	*mul = x * y;		// ��x��y�Ļ�����*mul
}

int main()
{
	int a, b;
	int he = 0, ji = 0;

	cout << "����a��";   cin >> a;
	cout << "����b��";   cin >> b;

	sum_mul(a, b, &he, &ji);		// ����a��b�ĺ����

	cout << "��Ϊ" << he   << "��\n";
	cout << "��Ϊ" << ji << "��\n";
}
