// �����˻��ࣨ��5�棺Դ�ļ���

#include <string>
#include <iostream>
#include "Account.h"

using namespace std;

//--- ���캯�� ---//
Account::Account(string name, string num, long amnt, int y, int m, int d)
														 : open(y, m, d)
{
	full_name = name;		// �˻�����
	number = num;			// �˺�
	crnt_balance = amnt;	// �˻����
}

//--- ���� ---//
void Account::deposit(long amnt)
{
	crnt_balance += amnt;
}

//--- ȡ�� ---//
void Account::withdraw(long amnt)
{
	crnt_balance -= amnt;
}
