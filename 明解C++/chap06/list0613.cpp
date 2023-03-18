// ���޷����������а�λ�롢��λ�򡢰�λ���Ͱ�λȡ�����㣬����ʾ������

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
	unsigned a, b;

	cout << "�����������Ǹ�������\n";
	cout << "a : ";	  cin >> a;
	cout << "b : ";	  cin >> b;

	cout << "a     = ";  print_bits(a);		cout << '\n';
	cout << "b     = ";  print_bits(b);		cout << '\n';
	cout << "a & b = ";  print_bits(a & b);	cout << '\n';	// ��λ��
	cout << "a | b = ";  print_bits(a | b);	cout << '\n';	// ��λ��
	cout << "a ^ b = ";  print_bits(a ^ b);	cout << '\n';	// ��λ���
	cout << "~a    = ";  print_bits(~a);	cout << '\n';	// ��λȡ��
	cout << "~b    = ";  print_bits(~b);	cout << '\n';	// ��λȡ��
}
