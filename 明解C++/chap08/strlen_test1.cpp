// strlen������ʹ�����̣���һ��

#include <cstring>
#include <iostream>

using namespace std;

int main(void)
{
	char str[100];

	cout << "�������ַ�����";
	cin >> str;

	cout << "�ַ���\"" << str << "\"�ĳ���Ϊ" << strlen(str) << "��\n";
}
