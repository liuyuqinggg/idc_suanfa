// ������Complex��ʹ������

#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
	double re, im;

	cout << "a��ʵ����";  cin >> re;
	cout << "a���鲿��";  cin >> im;
	Complex a(re, im);

	cout << "b��ʵ����";  cin >> re;
	cout << "b���鲿��";  cin >> im;
	Complex b(re, im);

	Complex c = -a + b;

	b += 2.0;						// b����(2.0,0.0)
	c -= Complex(1.0, 1.0);			// c��ȥ(1.0,1.0)
	Complex d(b.imag(), c.real());	// ����d��b��ʵ��, c���鲿��

	cout << "a = " << a << '\n';
	cout << "b = " << b << '\n';
	cout << "c = " << c << '\n';
	cout << "d = " << d << '\n';
}
