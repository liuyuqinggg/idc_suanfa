// �ѽ��յ��ַ����е�Сд��ĸת��Ϊ��д��ĸ����ʾ

#include <cctype>
#include <iostream>

using namespace std;

//--- ��ʾ�ַ���s����Сд��ĸת��Ϊ��д��ĸ��---//
void put_upper(const char s[])
{
	for (int i = 0; s[i]; i++)
		cout << static_cast<char>(toupper(s[i]));
}

int main()
{
	char str[36];

	cout << "�ַ�����";
	cin >> str;

	put_upper(str);
	cout << '\n';
}
