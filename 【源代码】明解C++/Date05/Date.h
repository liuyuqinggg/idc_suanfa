// ������Date����5�棺ͷ�ļ���

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
	static int days_of_year(int y);				// y�������
	static int days_of_month(int y, int m);		// y��m�µ�����

	// ���������£�����1~12�ķ�Χ֮��Ĳ���ȷ��ֵ��
	static int adjusted_month(int m);

	// ��������y��m�µ�d�գ�����1~28/29/30/31�ķ�Χ֮��Ĳ���ȷ��ֵ��
	static int adjusted_day(int y, int m, int d);

public:
	Date();										// Ĭ�Ϲ��캯��
	Date(int yy, int mm = 1, int dd = 1);		// ���캯��

	//--- year���������� ---//
	static bool leap_year(int year) {
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}

	int year()  const { return y; }			// ������
	int month() const { return m; }			// ������
	int day()   const { return d; }			// ������

	void set_year( int yy);					// ������Ϊyy
	void set_month(int mm);					// ������Ϊmm
	void set_day(  int dd);					// ������Ϊdd

	void set(int yy, int mm, int dd);		// ��������Ϊyy��mm��dd��

	bool leap_year() const { return leap_year(y); }		// ��������

	Date preceding_day() const;				// ����ǰһ�������
	Date following_day() const;				// ���غ�һ�������

	int day_of_year() const;				// ����ĳ���ڵľ�������

	int day_of_week() const;				// ��������

	std::string to_string() const;			// �����ַ�����ʾ

	Date& operator++();							// ���һ�죨ǰ�õ�����
	Date  operator++(int);						// ���һ�죨���õ�����

	Date& operator--();							// ��ǰһ�죨ǰ�õݼ���
	Date  operator--(int);						// ��ǰһ�죨���õݼ���

	Date& operator+=(int n);					// ���n�죨Date += int��
	Date& operator-=(int n);					// ��ǰn�죨Date -= int��

	Date operator+(int n) const;					 // ��n�������ڣ�Date + int��
	friend Date operator+(int n, const Date& date);  // ��n�������ڣ�int + Date��

	Date operator-(int n) const;				// ��n��ǰ�����ڣ�Date - int��

	long operator-(const Date& day) const;		// �����ڵĲDate - Date��

	bool operator==(const Date& day) const;		// ��day��ͬ��
	bool operator!=(const Date& day) const;		// ��day��ͬ��

	bool operator> (const Date& day) const;		// ��day������
	bool operator>=(const Date& day) const;		// ��day֮����
	bool operator< (const Date& day) const;		// ��day��ǰ��
	bool operator<=(const Date& day) const;		// ��da֮ǰ��
};

std::ostream& operator<<(std::ostream& s, const Date& x);	// �����
std::istream& operator>>(std::istream& s,       Date& x);	// ��ȡ��

#endif
