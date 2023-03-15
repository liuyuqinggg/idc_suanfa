// ������Date����ӳ�Ա�������ô�����

#include <iostream>

using namespace std;

class Date {
	int y;		// ������
	int m;		// ��
	int d;		// ��
	mutable int counter;	// ��Ա�����ĵ��ô���

public:
	Date(int yy, int mm, int dd) {					// ���캯��
		y = yy;  m = mm;  d = dd;  counter = 0;
	}
	int year()  const { counter++; return y; }		// ������
	int month() const { counter++; return m; }		// ������
	int day()   const { counter++; return d; }		// ������
	int count() const { return counter; }			// ���ش���
};

int main()
{
	const Date birthday(1963, 11, 18);		// ����

	cout << "birthday = " << birthday.year()  << "��"
						  << birthday.month() << "��"
						  << birthday.day()	  << "��\n";
	cout << "birthday�ĳ�Ա������������" << birthday.count() << 
			"�Ρ�\n";
}
