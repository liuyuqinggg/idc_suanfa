// �������д���ַ�������ʾ����ʼ����

#include <iostream>

using namespace std;

int main()
{
	char s1[] = {'A', 'B', 'C', '\0'};
	char s2[] = {"ABC"};
	char s3[] = "ABC";

	cout << "�ַ���\"" << s1 << "\"���������s1�С�\n";
	cout << "�ַ���\"" << s2 << "\"���������s2�С�\n";
	cout << "�ַ���\"" << s3 << "\"���������s3�С�\n";
}
