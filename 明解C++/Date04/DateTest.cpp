// ������Date����4�棩��ʹ������

#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	Date today;		// ����

	cout << "��������ڣ�" << today << '\n';

	cout << "��������ڣ�" << today.preceding_day() << '\n';
	cout << "ǰ������ڣ�" << today.preceding_day().preceding_day() << '\n';

	cout << "��������ڣ�" << today.following_day() << '\n';
	cout << "��������ڣ�" << today.following_day().following_day() << '\n';

	cout << "��Ԫ����ʼ������" << today.day_of_year() << "�졣\n";

	cout << "����"
		 << (today.is_leap() ? "�����ꡣ" : "�������ꡣ") << '\n';

	int y, m, d;

	cout << "�����꣺";
	cin >> y;

	cout << "����"
		 << (Date::is_leap(y) ? "�����ꡣ" : "�������ꡣ") << '\n';
}
