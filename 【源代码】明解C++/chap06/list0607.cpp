// ������

#include <iostream>

using namespace std;

//--- ����x��n�η� ---//
double power(double x, int n)
{
	double tmp = 1.0;

	while (n-- > 0)
		tmp *= x;	// tmp����x
	return tmp;
}

int main()
{
	double a;
	int    b;

	cout << "����a��b�η���\n";
	cout << "ʵ��a��";	cin >> a;
	cout << "����b��";	cin >> b;
	cout << a << "��" << b << "�η�Ϊ" << power(a, b) << "��\n";
}
