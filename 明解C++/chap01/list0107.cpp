// ��ʾ��������x��y�ĺͼ�ƽ��ֵ

#include <iostream>

using namespace std;

int main()
{
	int x;		// x��int�ͱ���
	int y;		// y��int�ͱ���

	x = 63;		// ��63��ֵ��x
	y = 18;		// ��18��ֵ��y

	cout << "x��ֵ��" << x << "��\n";			// ��ʾx��ֵ
	cout << "y��ֵ��" << y << "��\n";			// ��ʾy��ֵ
	cout << "����" << x + y << "��\n";		// ��ʾx��y�ĺ�
	cout << "ƽ��ֵ��" << (x + y) / 2 << "��\n";	// ��ʾx��y��ƽ��ֵ
}
