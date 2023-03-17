// �����˻��ࣨ��6�棺ͷ�ļ���

#ifndef ___Class_Account
#define ___Class_Account

#include <string>
#include "Date.h"

//===== �����˻��� =====//
class Account {
	std::string full_name;	// �˻�����
	std::string number;		// �˺�
	long crnt_balance;		// �˻����
	Date open;				// ��������

public:
	// ���캯��
	Account(std::string name, std::string num, long amnt, const Date& op);

	void deposit(long amnt);							// ����
	void withdraw(long amnt);							// ȡ��

	std::string name() const  { return full_name; }		// �����˻�����
	std::string no() const    { return number; }		// �����˺�
	long balance() const      { return crnt_balance; }	// �����˻����
	Date opening_date() const { return open; }			// ���ؿ�������
};

#endif
