// strcpy������strncpy������ʹ������

#include <cstring>
#include <iostream>

using namespace std;

int main(void)
{
	char tmp[16];
	char s1[16], s2[16], s3[16];

	cout << "�������ַ�����";
	cin >> tmp;

	strcpy(s1, strcpy(s2, tmp));	// ���ַ������Ƶ�s1��s2

	cout << "�ַ���s1Ϊ\"" << s1 << "\"��\n";
	cout << "�ַ���s2Ϊ\"" << s2 << "\"��\n";
	cout << "�ַ���s3Ϊ\"" << strcpy(s3, tmp) << "\"��\n";

	char* x = "XXXXXXXXX";			// 9��'X'��1�����ַ�

	strcpy(s3, x); strncpy(s3, "12345", 3);		 cout << "s3 = " << s3 << '\n';
	strcpy(s3, x); strncpy(s3, "12345", 5);		 cout << "s3 = " << s3 << '\n';
	strcpy(s3, x); strncpy(s3, "12345", 7);		 cout << "s3 = " << s3 << '\n';
	strcpy(s3, x); strncpy(s3, "1234567890", 9); cout << "s3 = " << s3 << '\n';
}
