// ������������ֵ��ʵ��ƽ��ֵ����һ��

#include <iostream>

using namespace std;

int main()
{
	int x, y;

	cout << "������������ֵx��y��ƽ��ֵ��\n";
	cout << "x��ֵ��";	cin >> x;	// ��x��������ֵ
	cout << "y��ֵ��";	cin >> y;	// ��y��������ֵ

	double ave = (x + y) / 2.0;						// ����ʵ��ƽ��ֵ
	cout << "x��y��ƽ��ֵΪ" << ave << "��\n";	// ��ʾƽ��ֵ
}
