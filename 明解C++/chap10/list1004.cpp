// �����˻��ࣨ��3�棺�����Ա�����Ķ��壩�����ʹ������

#include <string>
#include <iostream>

using namespace std;

class Account {
	string full_name;		// �˻�����
	string number;			// �˺�
	long crnt_balance;		// �˻����

public:
	Account(string name, string num, long amnt);	// ���캯��

	string name()  { return full_name; }			// �����˻�����
	string no()    { return number; }				// �����˺�
	long balance() { return crnt_balance; }			// �����˻����

	void deposit(long amnt);						// ����
	void withdraw(long amnt);						// ȡ��
};

//--- ���캯�� ---//
Account::Account(string name, string num, long amnt)
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

int main()
{
	Account liyang("����", "12345678", 1000);		    // �������˻�
	Account zhouyan("����", "87654321",  200);		// ������˻�

	liyang.withdraw(200);			// ����ȡ��200Ԫ
	zhouyan.deposit(100);			// �������100Ԫ

	cout << "�������˻���\"" << liyang.name() << "\" (" << liyang.no()
		 << ") " << liyang.balance() << "Ԫ\n";

	cout << "������˻���\"" << zhouyan.name() << "\" (" << zhouyan.no()
		 << ") " << zhouyan.balance() << "Ԫ\n";
}
