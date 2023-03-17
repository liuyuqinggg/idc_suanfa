// ������Date����4�棺ͷ�ļ���

#ifndef ___Class_Date
#define ___Class_Date

#include <string>
#include <iostream>

//===== ������ =====//
class Date {
	int y;	// ������
	int m;	// ��
	int d;	// ��
	static int dmax[];
	static int days_of_month(int y, int m);		// y��m�µ�����

public:
	Date();										// Ĭ�Ϲ��캯��
	Date(int yy, int mm = 1, int dd = 1);		// ���캯��

	// year����������
	static bool is_leap(int year) {
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}

	int year()  const { return y; }			// ������
	int month() const { return m; }			// ������
	int day()   const { return d; }			// ������
	bool is_leap() const { return is_leap(y); }		// ��������
	Date preceding_day() const;				// ����ǰһ�������
	Date following_day() const;				// ���غ�һ�������

	int day_of_year() const;				// ����ĳ���ڵľ�������

	int day_of_week() const;				// ��������

	std::string to_string() const;			// �����ַ�����ʾ
};

std::ostream& operator<<(std::ostream& s, const Date& x);		// �����
std::istream& operator>>(std::istream& s, Date& x);				// ��ȡ��

#endif
