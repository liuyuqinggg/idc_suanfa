// strcmp������strncmp������ʹ������

#include <cstring>
#include <iostream>

using namespace std;

int main(void)
{
	char st[128];

	cout << "\"��"ABCDE"���бȽϡ�\n";
	cout << "\"��"XXXXX"������\n";

	while (1) {
		cout << "\n�ַ���st��";
		cin >> st;

		if (strcmp(st, "XXXXX") == 0)
			break;
		cout << "strcmp( \"ABCDE\", st)    = " << strcmp( "ABCDE", st) << '\n';
		cout << "strncmp(\"ABCDE\", st, 3) = " << strncmp("ABCDE", st, 3) << '\n';
	}
}