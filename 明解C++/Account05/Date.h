// ������Date����2�棺ͷ�ļ���

#include <string>
#include <iostream>

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

	std::string to_string() const;		// �����ַ�����ʾ
};

std::ostream& operator<<(std::ostream& s, const Date& x);	// �����
std::istream& operator>>(std::istream& s, Date& x);			// ��ȡ��