// ������Complex

#ifndef ___Class_Complex
#define ___Class_Complex

#include <iostream>

//===== ������ =====//
class Complex {
	double re;		// ʵ��
	double im;		// �鲿

public:
	Complex(double r = 0, double i = 0) : re(r), im(i) { }	 // ���캯��

	double real() const { return re; }		// ����ʵ��
	double imag() const { return im; }		// �����鲿

	Complex operator+() const { return *this; }				 // һԪ+�����
	Complex operator-() const { return Complex(-re, -im); }	 // һԪ-�����

	//--- ���ϸ�ֵ����� ---//
	Complex& operator+=(const Complex& x) {
		re += x.re;
		im += x.im;
		return *this;
	}

	//--- ���ϸ�ֵ����� ---//
	Complex& operator-=(const Complex& x) {
		re -= x.re;
		im -= x.im;
		return *this;
	}

	//--- �������� ---//
	friend bool operator==(const Complex& x, const Complex& y) {
		return x.re == y.re && x.im == y.im;
	}

	//--- �������� ---//
	friend bool operator!=(const Complex& x, const Complex& y) {
		return !(x == y);
	}

	//--- ��Ԫ+�������Complex + Complex��---//
	friend Complex operator+(const Complex& x, const Complex& y) {
		return Complex(x.re + y.re, x.im + y.im);
	}

	//--- ��Ԫ+�������double + Complex��---//
	friend Complex operator+(double x, const Complex& y) {
		return Complex(x + y.re, y.im);
	}

	//--- ��Ԫ+�������Complex + double��---//
	friend Complex operator+(const Complex& x, double y) {
		return Complex(x.re + y, x.im);
	}
};

//--- �������s����x ---//
inline std::ostream& operator<<(std::ostream& s, const Complex& x)
{
	return s << '(' << x.real() << ", " << x.imag() << ')';
}

#endif
