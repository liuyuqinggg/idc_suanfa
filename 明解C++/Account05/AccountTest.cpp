// �����˻��ࣨ��5�棩��ʹ������

#include <iostream>
#include "Account.h"

using namespace std;

int main()
{
	Account liyang("����", "12345678", 1000, 2125, 1, 24);  // �������˻�
	Account zhouyan("����", "87654321",  200, 2123, 7, 15);   // ������˻�

	liyang.withdraw(200);	// ����ȡ��200Ԫ
	zhouyan.deposit(100);	// �������100Ԫ

	cout << "�������˻�\n";
	cout << "�˻�����=" << liyang.name() << '\n';
	cout << "�˺�=" << liyang.no() << '\n';
	cout << "�˻����=" << liyang.balance() << "Ԫ\n";
	cout << "��������=" << liyang.opening_date() << '\n';

	cout << "\n������˻�\n";
	cout << "�˻�����=" << zhouyan.name() << '\n';
	cout << "�˺�=" << zhouyan.no() << '\n';
	cout << "�˻����=" << zhouyan.balance() << "Ԫ\n";
	cout << "��������=" << zhouyan.opening_date().year()  << "��"
						 << zhouyan.opening_date().month() << "��"
						 << zhouyan.opening_date().day()   << "��\n";
}
