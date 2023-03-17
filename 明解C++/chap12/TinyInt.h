#ifndef ___TinyInt
#define ___TinyInt

#include <climits>
#include <iostream>

//--- С������ ---//
class TinyInt {
	int v;			// ֵ

public:
	TinyInt(int value = 0) : v(value) { }		//--- ���캯�� ---//

	operator int() const { return v; }			//--- int��ת������  ---//

	bool operator!() const { return v == 0; }	//--- �߼�������� ---//

	TinyInt& operator++() { 		//--- ǰ�õ�������� ---//
		if (v < INT_MAX) v++;			// ֵ������ΪINT_MAX
		return *this;					// �������������
	}

	TinyInt operator++(int) {		//--- ���õ�������� ---//
		TinyInt x = *this;				// �������ǰ��ֵ
		++(*this);						// ʹ��ǰ�õ��������ִ�е���
		return x;						// ���ظղű����ֵ
	}

	friend TinyInt operator+(const TinyInt& x, const TinyInt& y) {	// x + y
		return TinyInt(x.v + y.v);
	}

	//--- ���ϸ�ֵ����� ---//
	TinyInt& operator+=(const TinyInt& x) { v += x.v; return *this; }

	friend bool operator==(const TinyInt& x, const TinyInt& y) { return x.v == y.v; }

	friend bool operator!=(const TinyInt& x, const TinyInt& y) { return x.v != y.v; }

	friend bool operator> (const TinyInt& x, const TinyInt& y) { return x.v >  y.v; }

	friend bool operator>=(const TinyInt& x, const TinyInt& y) { return x.v >= y.v; }

	friend bool operator< (const TinyInt& x, const TinyInt& y) { return x.v <  y.v; }

	friend bool operator<=(const TinyInt& x, const TinyInt& y) { return x.v <= y.v; }

	friend std::ostream& operator<<(std::ostream& s, const TinyInt& x) {
		return s << x.v;
	}
};

#endif
