// ������

#include <iostream>

using namespace std;

//--- ����x��n�η� ---//
double power(double x, int n)
{
	double tmp = 1.0;

	for (int i = 1; i <= n; i++)
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
