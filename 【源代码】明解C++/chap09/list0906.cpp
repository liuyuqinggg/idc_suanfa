// ������

#include <iostream>

using namespace std;

//--- ����x��n�η� ---//
double power(double x, int n);

int main()
{
	double a;
	int    b;

	cout << "����a��b�η���\n";
	cout << "ʵ��a��";	cin >> a;
	cout << "����b��";	cin >> b;
	cout << a << "��" << b << "�η�Ϊ" <<
			power(a, b) << "��\n";
}
