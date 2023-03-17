// ���޷����������а�λ�롢��λ�򡢰�λ���Ͱ�λȡ�����㣬����ʾ������
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
