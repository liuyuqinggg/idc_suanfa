// ������Date����5�棺Դ�ļ���

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
	return dmax[m - 1] + (m == 2 && leap_year(y));
}

//--- year���������ƽ��...365/����...366��---//
int Date::days_of_year(int year)
{
	return 365 + leap_year(year);
}

//--- ���������£�����1~12�ķ�Χ֮��Ĳ���ȷ��ֵ��---//
int Date::adjusted_month(int m)
{
	return m < 1 ? 1 : m > 12 ? 12 : m;
}

//--- ��������y��m�µ�d�գ�����1~28/29/30/31�ķ�Χ֮��Ĳ���ȷ��ֵ��---//
int Date::adjusted_day(int y, int m, int d)
{
	if (d < 1)
		return 1;

	int max_day = days_of_month(y, m);		// y��m�µ�����

	return d > max_day ? max_day : d;
}

//--- Date��Ĭ�Ϲ��캯��������Ϊ��ǰ���ڣ�---//
Date::Date()
{
	time_t current = time(NULL);				// ��ȡ��ǰ����ʱ��
	struct tm* local = localtime(&current);		// ת��Ϊ�ֽ�ʱ��

	y = local->tm_year + 1900;		// �꣺tm_yearΪ������-1900
	m = local->tm_mon + 1;			// �£�tm_monΪ0~11
	d = local->tm_mday;				// ��
}

//--- Date�Ĺ��캯��������Ϊָ�������գ�---//
Date::Date(int yy, int mm, int dd)
{
	set(yy, mm, dd);				// ��������Ϊyy��mm��dd��
}

//--- ������Ϊyy ---//
void Date::set_year(int yy)
{
	y = yy;							// ��
	d = adjusted_day(y, m, d);		// �գ���������ȷ��ֵ��
}

//--- ������Ϊmm ---//
void Date::set_month(int mm)
{
	m = adjusted_month(mm);			// �£���������ȷ��ֵ��
	d = adjusted_day(y, m, d);		// �գ���������ȷ��ֵ��
}

//--- ������Ϊdd ---//
void Date::set_day(int dd)
{
	d = adjusted_day(y, m, dd);		// �գ���������ȷ��ֵ��
}

//--- ��������Ϊyy��mm��dd�� ---//
void Date::set(int yy, int mm, int dd)
{
	y = yy;							// ��
	m = adjusted_month(mm);			// �£���������ȷ��ֵ��
	d = adjusted_day(y, m, dd);		// �գ���������ȷ��ֵ��
}

//--- ����ǰһ������� ---//
Date Date::preceding_day() const
{
	Date temp(*this);				// ����*this�ĸ���
	return --temp;					// ���㸱����ǰһ�����ڲ�����
}

//--- ���غ�һ������� ---//
Date Date::following_day() const
{
	Date temp(*this);				// ����*this�ĸ���
	return ++temp;					// ���㸱���ĺ�һ�����ڲ�����
}

//--- ����ĳ���ڵľ������� ---//
int Date::day_of_year() const
{
	int days = d;	// ĳ���ڵľ�������

	for (int i = 1; i < m; i++)			// �ۼ�1��~(m-1)�µ�����
		days += days_of_month(y, i);
	return days;
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

//--- �����ַ�����ʾ ---//
string Date::to_string() const
{
	ostringstream s;
	s << y << "��" << m << "��" << d << "��";
	return s.str();
}

//--- ���һ�죨ǰ�õ�����++(*this)��---//
Date& Date::operator++()
{
	if (d < days_of_month(y, m))	// �������ĩ��ǰ
		d++;						// ֻ�������
	else {							// ����һ��
		if (++m > 12) {				// �������12��
			y++;					// ����һ���...
			m = 1;					// 1��
		}
		d = 1;						// ��Ϊ��һ�µ�1��
	}
	return *this;
}

//--- ���һ�죨���õ�����(*this)++��---//
Date Date::operator++(int)
{
	Date temp(*this);				// ���Ƶ���ǰ��ֵ
	++(*this);						// ʹ��ǰ�õ��������++������
	return temp;					// ���ظ���
}

//--- ��ǰһ�죨ǰ�õݼ���--(*this)��---//
Date& Date::operator--()
{
	if (d > 1)						// ������³�
		d--;						// ֻ��ݼ���
	else {							// ��ǰһ��
		if (--m <= 1) {				// �������1��
			y--;					// ��ǰһ���
			m = 12;					// 12��
		}
		d = days_of_month(y, m);	// ��Ϊǰһ�µ���ĩ
	}
	return *this;
}

//--- ��ǰһ�죨���õݼ���(*this)--��---//
Date Date::operator--(int)
{
	Date temp(*this);				// ���Ƶݼ�ǰ��ֵ
	--(*this);						// ʹ��ǰ�õݼ������--���ݼ�
	return temp;					// ���ظ���
}

//--- ���n�죨���ϸ�ֵ��*this += n��---//
Date& Date::operator+=(int n)
{
	if (n < 0)							// ���nΪ��
		return *this -= -n;			// ί�������-=����

	d += n;							// �ռ�n

	while (d > days_of_month(y, m)) {	// ��������ʹ�������µ�������Χ��
		d -= days_of_month(y, m);
		if (++m > 12) {
			y++;
			m = 1;
		}
	}
	return *this;
}

//--- ��ǰn�죨���ϸ�ֵ��*this -= int��---//
Date& Date::operator-=(int n)
{
	if (n < 0)							// ���nΪ��
		return *this += -n;			// ί�������+=����

	d -= n;							// �ռ�n

	while (d < 1) {						// ��������ʹ����Ϊ��
		if (--m < 1) {
			y--;
			m = 12;
		}
		d += days_of_month(y, m);
	}
	return *this;
}

//--- ��n�������ڣ��ӷ���*this + n��---//
Date Date::operator+(int n) const
{
	Date temp(*this);
	return temp += n;						// ʹ�������+=
}

//--- ��day��n�������ڣ��ӷ���n + day��---//
Date operator+(int n, const Date& day)
{
	return day + n;						// ί��Date + int�������+����
}

//--- ��date��n��ǰ�����ڣ�������*this - n��---//
Date Date::operator-(int n) const
{
	Date temp(*this);
	return temp -= n;						// ʹ�������-=
}

//--- �����ڵĲ������*this - day��---//
long Date::operator-(const Date& day) const
{
	long count;
	long count1 = this->day_of_year();	// *this�����ھ�������
	long count2 = day.day_of_year();	// day  �����ھ�������

	if (y == day.y)										// *this��dayΪͬһ��
		count = count1 - count2;
	else if (y > day.y) {								// *this����
		count = days_of_year(day.y) - count2 + count1;
		for (int yy = day.y + 1; yy < y; yy++)
			count += days_of_year(yy);
	} else {											// *this��ǰ
		count = -(days_of_year(y) - count1 + count2);
		for (int yy = y + 1; yy < day.y; yy++)
			count -= days_of_year(yy);
	}

	return count;
}

//--- ��day��ͬ�𣿣���ȣ�*this == day��---//
bool Date::operator==(const Date& day) const
{
	return y == day.y && m == day.m && d == day.d;
}

//--- ��day��ͬ�𣿣���ȣ�*this != day��---//
bool Date::operator!=(const Date& day) const
{
	return !(*this == day);						// ʹ�������==
}

//--- ��day������������𣿣���ϵ��*this > day��---//
bool Date::operator>(const Date& day) const
{
	if (y > day.y) return true;		// ��ͬ�꣨�£�
	if (y < day.y) return false;	// ��ͬ�꣨�ɣ�

	if (m > day.m) return true;		// ��ͬ��-��ͬ�£��£�
	if (m < day.m) return false;	// ��ͬ��-��ͬ�£��ɣ�

	return d > day.d;				// ��ͬ��-��ͬ�£��Ƚ��գ�
}

//--- day֮��������𣿣���ϵ��*this >= day��---//
bool Date::operator>=(const Date& day) const
{
	return !(*this < day);						// ʹ�������<
}

//--- ��day��ǰ�ľ������𣿣���ϵ��*this < day��---//
bool Date::operator<(const Date& day) const
{
	if (y < day.y) return true;		// ��ͬ�꣨�ɣ�
	if (y > day.y) return false;	// ��ͬ�꣨�£�

	if (m < day.m) return true;		// ��ͬ��-��ͬ�£��ɣ�
	if (m > day.m) return false;	// ��ͬ��-��ͬ�£��£�

	return d < day.d;				// ��ͬ��-��ͬ�£��Ƚ��գ�
}

//--- day֮ǰ�������𣿣���ϵ��*this <= day��---//
bool Date::operator<=(const Date& day) const
{
	return !(*this > day);						// ʹ�������>
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