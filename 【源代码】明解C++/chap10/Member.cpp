//--- ��Ա�ࣨԴ�ļ���---//

#include <iostream>
#include "Member.h"

using namespace std;

// ���캯�������塿
Member::Member(string name, int number, int grade)
{
	full_name = name;  no = number;  rank = grade;
}

// ��ʾ�����塿
void Member::print()
{
	cout << "No." << no << "��" << full_name << "[�ȼ���" << rank << "]\n";
}
