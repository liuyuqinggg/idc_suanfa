// ��������Counter����1�棩��ʹ������

#include <iostream>
#include "Counter.h"

using namespace std;

int main()
{
	int no;
	Counter x;

	cout << "��ǰ�ļ�������" << x.value() << '\n';

	cout << "���ϼ���������";
	cin >> no;

	for (int i = 0; i < no; i++) {
		x.increment();					// ���ϼ���
		cout << x.value() << '\n';
	}

	cout << "���¼���������";
	cin >> no;

	for (int i = 0; i < no; i++) {
		x.decrement();					// ���¼���
		cout << x.value() << '\n';
	}
}
