// strlen������ʹ������

#include <cstring>
#include <iostream>

using namespace std;

//--- strlen��ʵ������A ---//

#include <cstddef>

size_t strlen(const char* s)
{
	size_t len = 0;		// ����

	while (*s++)
		len++;
	return len;
}

int main(void)
{
	char str[100];

	cout << "�������ַ�����";
	cin >> str;

	cout << "�ַ���\"" << str << "\"�ĳ���Ϊ" << strlen(str) << "��\n";
}
