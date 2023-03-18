// ������Date����4�棺Դ�ļ���

#include <ctime>
#include <sstream>
#include <iostream>
#include "Date.h"

using namespace std;

// ƽ��ĸ��µ�����
int Date::dmax[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//--- ����y��m�µ����� ---//
int Date::days_of_month(int y, int m)
{
	return dmax[m - 1] + (is_leap(y) && m == 2);
}

//--- Date��Ĭ�Ϲ��캯��������Ϊ��ǰ���ڣ�---//
Date::Date()
{
	time_t current = time(NULL);				// ��ȡ��ǰ����ʱ��
	struct tm* local = localtime(&current);		// ת��Ϊ�ֽ�ʱ��

	y = local->tm_year + 1900;		// �꣺tm_yearΪ������-1900
	m = local->tm_mon + 1;			// �£�tm_monΪ0~11
	d = local->tm_mday;
}

//--- Date�Ĺ��캯��������Ϊָ�����ꡢ�¡��գ�---//
Date::Date(int yy, int mm, int dd)
{
	y = yy;
	m = mm;
	d = dd;
}

//--- ����ĳ���ڵľ������� ---//
int Date::day_of_year() const
{
	int days = d;	// ĳ���ڵľ�������

	for (int i = 1; i < m; i++)			// �ۼ�1��~(m-1)�µ�����
		days += days_of_month(y, i);
	return days;
}

//--- ����ǰһ������� ---//
Date Date::preceding_day() const
{
	Date temp = *this;		// ͬһ����

	if (temp.d > 1)
		temp.d--;
	else {
		if (--temp.m < 1) {
			temp.y--;
			temp.m = 12;
		}
		temp.d = days_of_month(temp.y, temp.m);
	}
	return temp;
}

//--- ���غ�һ������� ---//
Date Date::following_day() const
{
	Date temp = *this;		// ͬһ����

	if (temp.d < days_of_month(temp.y, temp.m))
		temp.d++;
	else {
		if (++temp.m > 12) {
			temp.y++;
			temp.m = 1;
		}
		temp.d = 1;
	}
	return temp;
}

//--- �����ַ�����ʾ ---//
string Date::to_string() const
{
	ostringstream s;
	s << y << "��" << m << "��" << d << "��";
	return s.str();
}

//--- �������ڣ�������~��������Ӧ0~6��---//
int Date::day_of_week() const
{
	int yy = y;
	int mm = m;
	if (mm == 1 || mm == 2) {
		yy--;
		mm += 12;
	}
	return (yy + yy / 4 - yy / 100 + yy / 400 + (13 * mm + 8) / 5 + d) % 7;
}

//--- �������s����x ---//
ostream& operator<<(ostream& s, const Date& x)
{
	return s << x.to_string();
}

//--- ��������s��ȡ���ڲ�����x ---//
istream& operator>>(istream& s, Date& x)
{
	int yy, mm, dd;
	char ch;

	s >> yy >> ch >> mm >> ch >> dd;
	x = Date(yy, mm, dd);
	return s;
}
