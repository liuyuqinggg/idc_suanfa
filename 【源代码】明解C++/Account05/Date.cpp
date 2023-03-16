// ������Date����2�棺Դ�ļ���

#include <ctime>
#include <sstream>
#include <iostream>
#include "Date.h"

using namespace std;

//--- Date��Ĭ�Ϲ��캯��������Ϊ��ǰ���ڣ�---//
Date::Date()
{
	time_t current = time(NULL);				// ��ȡ��ǰ������ʱ��
	struct tm* local = localtime(&current);		// ת��Ϊ�ֽ�ʱ��

	y = local->tm_year + 1900;		// �꣺tm_yearΪ��Ԫ��-1900
	m = local->tm_mon + 1;			// �£�tm_monΪ0 ~ 11
	d = local->tm_mday;				// ��
}

//--- Date�Ĺ��캯��������Ϊָ�������գ�---//
Date::Date(int yy, int mm, int dd)
{
	y = yy;
	m = mm;
	d = dd;
}

//--- ����ǰһ������ڣ���֧������Ĵ��� ---//
Date Date::preceding_day() const
{
	int dmax[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	Date temp = *this;		// ͬһ����

	if (temp.d > 1)
		temp.d--;
	else {
		if (--temp.m < 1) {
			temp.y--;
			temp.m = 12;
		}
		temp.d = dmax[temp.m - 1];
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

//--- �������s����x ---//
ostream& operator<<(ostream& s, const Date& x)
{
	return s << x.to_string();
}

//--- ��������s��ȡ���ڴ���x ---//
istream& operator>>(istream& s, Date& x)
{
	int yy, mm, dd;
	char ch;

	s >> yy >> ch >> mm >> ch >> dd;
	x = Date(yy, mm, dd);
	return s;
}

