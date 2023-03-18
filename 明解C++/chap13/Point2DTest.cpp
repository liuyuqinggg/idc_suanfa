#include <iostream>
#include "Point2D.h"

using namespace std;

int main()
{
	Point2D p;
	Point2D q(1, 3);
	Point2D a[] = {Point2D(1, 1), Point2D(2, 2)};

	cout << "�����ı�ʶ�ţ�" << Point2D::get_max_id() << '\n';
	cout << "p    = ";   p.print();   cout << "  ��ʶ�ţ�" << p.id() << '\n';
	cout << "q    = ";   q.print();   cout << "  ��ʶ�ţ�" << q.id() << '\n';
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		cout << "a[" << i << "] = ";   a[i].print();
		cout << "  ��ʶ�ţ�" << a[i].id() << '\n';
	}
}
