// ������Date����3�棺ͷ�ļ���

#ifndef ___Class_Date
#define ___Class_Date

#include <string>
#include <iostream>

//===== ������ =====//
class Date {
	int y;		// ��Ԫ��
	int m;		// ��
	int d;		// ��

public:
	Date();									// Ĭ�Ϲ��캯��
	Date(int yy, int mm = 1, int dd = 1);	// ���캯��

	int year()  const { return y; }		// ������
	int month() const { return m; }		// ������
	int day()   const { return d; }		// ������

	Date preceding_day() const;			// ����ǰһ������ڣ���֧������Ĵ���

	int day_of_week() const;			// �������� 

	std::string to_string() const;		// �����ַ�����ʾ
};

std::ostream& operator<<(std::ostream& s, const Date& x);	// �����
std::istream& operator>>(std::istream& s, Date& x);			// ��ȡ��

#endif
