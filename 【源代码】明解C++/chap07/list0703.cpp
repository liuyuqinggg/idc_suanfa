// ȡַ������ͽ����������

#include <iostream>

using namespace std;

int main()
{
	int x = 123, y = 567, sw;

	cout << "x = " << x << '\n';
	cout << "y = " << y << '\n';

	cout << "�޸�ֵ�ı�����";
	cin >> sw;

	int* ptr;
	if (sw == 0)
		ptr = &x;	// ptrָ��x
	else
		ptr = &y;	// ptrָ��y

	*ptr = 999;		// ��ptr��ָ�Ķ���ֵ

	cout << "x = " << x << '\n';
	cout << "y = " << y << '\n';
}
