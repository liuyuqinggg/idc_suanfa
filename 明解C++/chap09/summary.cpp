#include <iostream>
#include "maxof.h"

using namespace std;

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
