// ��ʾ���޷�������ֵ���ƺ����ƺ��ֵ

#include <iostream>

using namespace std;

//--- ��������x�С�1����λ�� ---//
int count_bits(unsigned x)
{
	int bits = 0;
	while (x) {
		if (x & 1U) bits++;
		x >>= 1;
	}
	return bits;
}

//--- ����int�ͻ�unsigned�͵�λ�� ---//
int int_bits()
{
	return count_bits(~0U);
}

//--- ��ʾunsigned�͵�����λ ---//
void print_bits(unsigned x)
{
	for (int i = int_bits() - 1; i >= 0; i--)
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
