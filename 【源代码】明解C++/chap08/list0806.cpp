// ��ʾ���յ��ַ���

#include <iostream>

using namespace std;

//--- ��ʾ�ַ���s ---//
void put_str(const char s[])
{
	for (int i = 0; s[i] != 0; i++)
		cout << s[i];
}

int main()
{
	char str[36];

	put_str("�ַ�����");
	cin >> str;

	put_str(str);
	cout << '\n';
}
