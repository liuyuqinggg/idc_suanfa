// ����������������˻�

#include <string>
#include <iostream>

using namespace std;

int main()
{
	string liyang_name    = "����";		    // �������˻�����
	string liyang_number  = "12345678";		// �������˺�
	long   liyang_balance = 1000;			// �������˻����

	string zhouyan_name    = "����";		    // ������˻�����
	string zhouyan_number  = "87654321";	// ������˺�
	long   zhouyan_balance = 200;			// ������˻����

	liyang_balance -= 200;					// ����ȡ��200Ԫ
	zhouyan_balance += 100;					// �������100Ԫ

	cout << "�������˻���\"" << liyang_name << "\" (" << liyang_number
		 << ") " << liyang_balance << "Ԫ\n";

	cout << "������˻���\"" << zhouyan_name << "\" (" << zhouyan_number
		 << ") " << zhouyan_balance << "Ԫ\n";
}
