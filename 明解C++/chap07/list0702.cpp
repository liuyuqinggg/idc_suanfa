// ָ��Ļ�����ȡַ������ͽ������������

#include <iostream>

using namespace std;

int main()
{
	int n = 135;
	cout << "n   ��" <<  n << '\n';
	cout << "&n  ��" << &n << "��ַ\n";

	int* ptr = &n;		// ptrָ��n
	cout << "ptr ��" <<  ptr << "��ַ\n";
	cout << "*ptr��" << *ptr << '\n';
}
