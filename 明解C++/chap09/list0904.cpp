// ��ʽ������������ֵ�еĽϴ�ֵ�ĺ���ģ��

#include <cstring>
#include <iostream>

using namespace std;

//--- ��a��b�еĽϴ�ֵ ---//
template <class Type> Type maxof(Type a, Type b)
{
	return a > b ? a : b;
}

//--- ��a��b�еĽϴ�ֵ��const char*�͵���������---//
template <> const char* maxof<const char*>(const char* a, const char* b)
{
	return strcmp(a, b) > 0 ? a : b;
}

int main()
{
	int a, b;
	char s[64], t[64];

	cout << "����a��";	  cin >> a;
	cout << "����b��";	  cin >> b;
	cout << "�ַ���s��";  cin >> s;
	cout << "�ַ���t��";  cin >> t;

	cout << "a��b�еĽϴ�ֵΪ" <<       maxof(a, b)                  << "��\n";
	cout << "s��t�еĽϴ�ֵΪ" <<       maxof<const char*>(s, t)     << "��\n";
	cout << "s��\"ABC\"�еĽϴ�ֵΪ" << maxof<const char*>(s, "ABC") << "��\n";
}
