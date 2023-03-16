// ����ֵ��Boolean��ʹ������

#include <iostream>
#include "Boolean.h"

using namespace std;

//--- ��������x��y�Ƿ���� ---//
Boolean int_eq(int x, int y)
{
	return x == y;
}

int main()
{
	int n;
	Boolean a;			// a <- False��Ĭ�Ϲ��캯��
	Boolean b = a;		// b <- False�����ƹ��캯��
	Boolean c = 100;	// c <- True��ת�����캯��
	Boolean x[8];		// x[0]~x[7]��Ĭ�Ϲ��캯��

	cout << "����ֵ��";
	cin >> n;
	x[0] = int_eq(n, 5);		// x[0]
	x[1] = (n != 3);			// x[1] <- Boolean(n != 3)
	x[2] = Boolean::False;		// x[2] <- False
	x[3] = 1000;				// x[3] <- True��Boolean(1000)
	x[4] = c == Boolean::True;	// x[4] <- Boolean(c == True)

	cout << "a��ֵ��" << int(a) << '\n';
	cout << "b��ֵ��" << static_cast<const char*>(b) << '\n';

	for (int i = 0; i < 8; i++)
		cout << "x[" << i << "] = " << x[i] << '\n';
}
