// ������ֵ�еĽϴ�ֵ������ֵ�е����ֵ�ĺ��������أ�

#include <iostream>

using namespace std;

//--- ����a��b�еĽϴ�ֵ ---//
int max(int a, int b)
{
	return a > b ? a : b;
}

//--- ����a��b��c�е����ֵ ---//
int max(int a, int b, int c)
{
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	return max;
}

int main()
{
	int x, y, z;

	cout << "x��ֵ��";
	cin >> x;

	cout << "y��ֵ��";
	cin >> y;

	// ����ֵ�еĽϴ�ֵ
	cout << "x��y�еĽϴ�ֵΪ" << max(x, y) << "��\n";

	cout << "z��ֵ";
	cin >> z;

	// ����ֵ�е����ֵ
	cout << "x��y��z�е����ֵΪ" << max(x, y, z) << "��\n";
}
