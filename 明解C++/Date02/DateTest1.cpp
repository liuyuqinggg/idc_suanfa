// ������Date����2�棩��ʹ�����̣�ȷ�ϳ�Ա����preceding_day�����ã�

#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	Date today;		// ����

	cout << "������" << today << "��\n";
	cout << "������" << today.preceding_day() << "��\n";
}
