// ��ʾ�����͵�λ��

#include <limits>
#include <iostream>

using namespace std;

int main()
{
	cout << "char �͵�λ����" << numeric_limits<unsigned char>::digits  << '\n';
	cout << "short�͵�λ����" << numeric_limits<unsigned short>::digits << '\n';
	cout << "int  �͵�λ����" << numeric_limits<unsigned int>::digits   << '\n';
	cout << "long �͵�λ����" << numeric_limits<unsigned long>::digits  << '\n';
}
