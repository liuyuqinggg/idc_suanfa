// ��ʾ�ַ����ַ�����
// ����

#include <cctype>
#include <climits>
#include <iostream>

using namespace std;

int main()
{
	cout << "�ô���ϵͳ���ַ����ַ�����\n";

	for (char i = 0; i <= CHAR_MAX; i++) {
		switch (i) {
		 case '\a' : cout << "\\a";  break;
		 case '\b' : cout << "\\b";  break;
		 case '\f' : cout << "\\f";  break;
		 case '\n' : cout << "\\n";  break;
		 case '\r' : cout << "\\r";  break;
		 case '\t' : cout << "\\t";  break;
		 case '\v' : cout << "\\v";  break;
		 default   : cout << ' ' << (isprint(i) ? i : ' ');
		}

		// ��ʮ����������ʾת��Ϊ���͵���ֵ
		cout << ' ' << hex << int(i) << '\n';
	}
}
