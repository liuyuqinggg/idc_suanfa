// ��������ֵ������0����һ��

#include <iostream>

using namespace std;

int main()
{
	int x;

	cout << "������\n";
	do {
		cout << "������ֵ��";
		cin >> x;
	} while (x <= 0);

	while (x >= 0) {
		cout << x << "\n";	// ��ʾx��ֵ
		x--;				// x��ֵ�ݼ���ֵ��1��
	}
}
