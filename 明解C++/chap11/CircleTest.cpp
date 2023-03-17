#include <iostream>
#include "Point2D.h"
#include "Circle.h"

using namespace std;

int main()
{
	Point2D origin(0, 0);			// ԭ��
	Circle c1(Point2D(3, 5), 7);	// ��������Ϊ(3, 5)���뾶Ϊ7��Բ
	Circle c2(Point2D(), 8);		// ��������Ϊ(0, 0)���뾶Ϊ8��Բ
	Circle c3(origin, 9);			// ��������Ϊ(0, 0)���뾶Ϊ9��Բ

	cout << "c1 = ";   c1.print();   cout << '\n';
	cout << "c2 = ";   c2.print();   cout << '\n';
	cout << "c3 = ";   c3.print();   cout << '\n';
}
