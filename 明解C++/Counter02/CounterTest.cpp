// ��������Counter����2�棩��ʹ������

#include <iostream>
#include "Counter.h"

using namespace std;

int main()
{
	int no;
	Counter x;
	Counter y;

	cout << "���ϼ���������";
	cin >> no;

	for (int i = 0; i < no; i++)		// ���ϼ�����xΪ���ö�yΪǰ�ã�
		cout << x++ << ' ' << ++y << '\n';

	cout << "���¼���������";
	cin >> no;

	for (int i = 0; i < no; i++)		// ���¼�����xΪ���ö�yΪǰ�ã�
		cout << x-- << ' ' << --y << '\n';

	if (!x)								// ���߼���������ж�
		cout << "xΪ0��\n";
	else 
		cout << "x��Ϊ0��\n";
}
