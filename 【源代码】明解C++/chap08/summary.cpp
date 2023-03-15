#include <iostream>

using namespace std;

//--- ��""��Χ�ַ���s����ʾ ---//
void put_str(const char* s)
{
	cout << '\"';
	while (*s)
		cout << *s++;
	cout << '\"';
}

int main()
{
	char a[] = "CIA";	// �ַ�����
	char* p  = "FBI";	// �ַ���ָ��
	char a2[][5] = {"LISP", "C", "Ada"};	// �ַ����������
	char* p2[]   = {"PAUL", "X", "MAC"};	// �ַ���ָ�������

	cout << "a = ";  put_str(a);  cout << '\n';
	cout << "p = ";  put_str(p);  cout << '\n';

	for (int i = 0; i < sizeof(a2) / sizeof(a2[0]); i++) {
		cout << "a2[" << i << "] = ";   put_str(a2[i]);   cout << '\n';
	}

	for (int i = 0; i < sizeof(p2) / sizeof(p2[0]); i++) {
		cout << "p2[" << i << "] = ";   put_str(p2[i]);   cout << '\n';
	}
}
