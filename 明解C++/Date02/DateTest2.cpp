// ������Date����2�棩��ʹ�����̣�ȷ�ϳ�Ա����to_string�����ã�

#include <iostream>
#include "Date.h"

using namespace std;
 
int main()
{
	const Date birthday(1963, 11, 18);		// ����
	Date day[3];							// ���飨��������ڣ�

	cout << "birthday = " << birthday << '\n';
	cout << "birthday���ַ�����ʾ��\"" << birthday.to_string() << "\"\n"; 

	for (int i = 0; i < 3; i++)
		cout << "day[" << i << "]���ַ�����ʾ��\"" << day[i].to_string() << "\"\n";
}
