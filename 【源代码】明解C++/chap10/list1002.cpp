// �����˻��ࣨ��1�棩�����ʹ������

#include <string>
#include <iostream>

using namespace std;

class Account {
public:
	string name;	// �˻�����
	string number;	// �˺�
	long balance;	// �˻����
};

int main()
{
	Account liyang;		    // �������˻�
	Account zhouyan;		// ������˻�

	liyang.name    = "����";	        // �������˻�����
	liyang.number  = "12345678";	// �������˺�
	liyang.balance = 1000;			// �������˻����

	zhouyan.name    = "����";      	// ������˻�����
	zhouyan.number  = "87654321";	// ������˺�
	zhouyan.balance = 200;			// ������˻����

	liyang.balance -= 200;			// ����ȡ��200Ԫ
	zhouyan.balance += 100;			// �������100Ԫ

	cout << "�������˻���\"" << liyang.name << "\" (" << liyang.number
		 << ") " << liyang.balance << "Ԫ\n";

	cout << "������˻���\"" << zhouyan.name << "\" (" << zhouyan.number
		 << ") " << zhouyan.balance << "Ԫ\n";
}
