// strlen������ʹ������

#include <cstring>
#include <iostream>

using namespace std;

//--- strlen��ʵ������B ---//

#include <cstddef>

size_t strlen(const char* s)
{
	const char* p = s;

	while (*s)
		s++;
	return s - p;
}

int main(void)
{
	char str[100];

	cout << "�������ַ�����";
	cin >> str;

	cout << "�ַ���\"" << str << "\"�ĳ���Ϊ" << strlen(str) << "��\n";
}
