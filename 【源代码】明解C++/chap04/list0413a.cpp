// ������������ֵ��ʵ��ƽ��ֵ����һ��
// ʹ��cast���ǿ��ת��

#include <iostream>

using namespace std;

int main()
{
	int x, y;

	cout << "������������ֵx��y��ƽ��ֵ��\n";
	cout << "x��ֵ��";	cin >> x;	// ��x��������ֵ
	cout << "y��ֵ��";	cin >> y;	// ��y��������ֵ

	double ave = (double)(x + y) / 2;				// ����ʵ��ƽ��ֵ
	cout << "x��y��ƽ��ֵΪ" << ave << "��\n";	// ��ʾƽ��ֵ
}
