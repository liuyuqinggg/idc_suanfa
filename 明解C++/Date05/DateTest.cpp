// ������Date����5�棩��ʹ������

#include <iostream>
#include "Date.h"

using namespace std;

//--- ��ʾ���ڵ������Ϣ ---//
void display(const Date& day)
{
	string dw[] = {"������", "����һ", "���ڶ�", "������", "������", "������", "������"};
	cout << "����" << day << "�������Ϣ\n";
	cout << "  ����" << dw[day.day_of_week()] << "";
	cout << "  ���ھ���������" << day.day_of_year() << "��";
	cout << "  ����" << (day.leap_year() ? "������" : "�������ꡣ") << '\n';
}

//--- �޸����� ---//
void change(Date& day)
{
	while (true) {
		cout << "[1]�޸��� [2]�޸��� [3]�޸��� [4]�޸������� "
			 << "[5]���n�� [6]��ǰn�� [0]���أ�";
		int selected;
		cin >> selected;

		if (selected == 0) return;

		int y, m, d, n;
		if (selected == 1 || selected == 4) { cout << "�꣺";   cin >> y; }
		if (selected == 2 || selected == 4) { cout << "�£�";   cin >> m; }
		if (selected == 3 || selected == 4) { cout << "�գ�";   cin >> d; }
		if (selected == 5 || selected == 6) { cout << "������"; cin >> n; }

		switch (selected) {
		 case 1: day.set_year(y);	break;		// ����Ϊy��
		 case 2: day.set_month(m);	break;		// ����Ϊm��
		 case 3: day.set_day(d);	break;		// ����Ϊd��
		 case 4: day.set(y, m, d);	break;		// ����Ϊy��m��d��
		 case 5: day += n;			break;		// ���n��
		 case 6: day -= n;			break;		// ��ǰn��
		}
		cout << "�޸�Ϊ" << day << "��\n";
	}
}

//--- ʹ�õ����͵ݼ������ ---//
void inc_dec(Date& day)
{
	while (true) {
		cout << "[1]++day  [2]day++  [3]--day  [4]day-- [0]�߂�F";
		int selected;
		cin >> selected;

		if (selected == 0) return;

		switch (selected) {
		 case 1: cout << "++day = " << ++day << '\n';  break;	// ǰ�õ���
		 case 2: cout << "day++ = " << day++ << '\n';  break;	// ���õ���
		 case 3: cout << "--day = " << --day << '\n';  break;	// ǰ�õݼ�
		 case 4: cout << "day-- = " << day-- << '\n';  break;	// ���õݼ�
		}
		cout << "day   = " << day << '\n';
	}
}

//--- ��֮ǰ��֮������� ---//
void before_after(Date& day)
{
	while (true) {
		cout << "[1]��һ�� [2]ǰһ�� [3]n���(day+n) [4]n���(n+day)"
			 << "[5]n��ǰ [0]���أ�";
		int selected;
		cin >> selected;

		if (selected == 0) return;

		int n;
		if (selected >= 3 && selected <= 5) {
			cout << "������";  cin >> n;
		}

		cout << "����";
		switch (selected) {
		 case 1: cout << day.following_day();	break;	// ��һ��
		 case 2: cout << day.preceding_day();	break;	// ǰһ��
		 case 3: cout << day + n;				break;	// n���Date + int��
		 case 4: cout << n   + day;				break;	// n���int  + Date��
		 case 5: cout << day - n;				break;	// n��ǰ��Date - int��
		}
		cout << "��\n";
	}
}

//--- ���������ڱȽ� ---//
void compare(const Date& day)
{
	int y, m, d;
	cout << "������Ƚ϶��������day2��\n";
	cout << "�꣺";  cin >> y;
	cout << "�£�";  cin >> m;
	cout << "�գ�";  cin >> d;

	Date day2(y, m, d);	// �Ƚ϶��������

	cout << boolalpha;
	cout << "day  = " << day  << '\n';
	cout << "day2 = " << day2 << '\n';
	cout << "day  -  day2  = " << (day  -  day2) << '\n';
	cout << "day2 -  day   = " << (day2 -  day ) << '\n';
	cout << "day  == day2  = " << (day  == day2) << '\n';
	cout << "day  != day2  = " << (day  != day2) << '\n';
	cout << "day  >  day2  = " << (day  >  day2) << '\n';
	cout << "day  >= day2  = " << (day  >= day2) << '\n';
	cout << "day  <  day2  = " << (day  <  day2) << '\n';
	cout << "day  <= day2  = " << (day  <= day2) << '\n';
}

int main()
{
	int y, m, d;
	cout << "����������day��\n";
	cout << "�꣺";  cin >> y;
	cout << "�£�";  cin >> m;
	cout << "�գ�";  cin >> d;

	Date day(y, m, d);	// ���������

	while (true) {
		cout << "[1]��ʾ��Ϣ [2]�޸����� [3]�����͵ݼ������ [4]֮ǰ��֮������� "
			 << "[5]�Ƚ� [0]������";

		int selected;
		cin >> selected;

		if (selected == 0) break;

		switch (selected) {
		 case 1: display(day);		break;	// ��ʾ���ڵ������Ϣ
		 case 2: change(day);		break;	// �޸�����
		 case 3: inc_dec(day);		break;	// ����������͵ݼ������
		 case 4: before_after(day);	break;	// ��֮ǰ��֮�������
		 case 5: compare(day);		break;	// ���������ڱȽ�
		}
	}
}
