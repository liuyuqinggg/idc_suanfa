// �����˻��ࣨ��4�棩��ʹ������

#include <string>
#include <iostream>
#include "Account.h"

using namespace std;

//--- ��ʾp��ָ��Account���˻���Ϣ���˻����ơ��˺š��˻��� ---//
void print_Account(string title, Account* p)
{
	cout << title
		 << p->name() << "\" (" << p->no() << ") " << p->balance() << "Ԫ\n";
}

int main()
{
	Account liyang("����", "12345678", 1000);		    // �������˻�
	Account zhouyan("����", "87654321",  200);		// ������˻�

	liyang.withdraw(200);			// ����ȡ��200Ԫ
	zhouyan.deposit(100);			// �������100Ԫ

	print_Account("�������˻�", &liyang);

	print_Account("������˻�", &zhouyan);
}
