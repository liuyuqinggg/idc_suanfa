// �����˻��ࣨ��6�棩��ʹ������

#include <iostream>
#include "Date.h"
#include "Account.h"

using namespace std;

int main()
{
	// �������˻�
	Account liyang("����", "12345678", 1000, Date(2125, 1, 24));
	string dw[] = {"������", "����һ", "���ڶ�", "������", "������", "������", "������"};

	cout << "�������˻�\n";
	cout << "�˻�����=" << liyang.name() << '\n';
	cout << "�˺�=" << liyang.no() << '\n';
	cout << "�˻����=" << liyang.balance() << "Ԫ\n";
	cout << "��������=" << liyang.opening_date();
	cout << "��" << dw[liyang.opening_date().day_of_week()] << "��\n";
}
