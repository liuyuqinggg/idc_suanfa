// ��ʾ���޷�������ֵ���ƺ����ƺ��ֵ
// ʹ��numeric_limits<unsigned>::digits

#include <limits>
#include <iostream>

using namespace std;

//--- ��ʾunsigned�͵�����λ ---//
void print_bits(unsigned x)
{
	for (int i = numeric_limits<unsigned>::digits - 1; i >= 0; i--)
		cout << ((x >> i) & 1U ? '1' : '0');
}

int main()
{
	unsigned x, n;

	cout << "�Ǹ�������";			cin >> x;
	cout << "Ҫ�ƶ���λ����";	        cin >> n;

	cout << "����   = ";  print_bits(x);		 cout << '\n';
	cout << "����   = ";  print_bits(x << n);	 cout << '\n';
	cout << "����   = ";  print_bits(x >> n);	 cout << '\n';
}
