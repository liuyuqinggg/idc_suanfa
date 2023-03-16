#ifndef ___Circle
#define ___Circle

#include "Point2D.h"

//--- Բ�� ---//
class Circle {
	Point2D center;		// ��������
	int radius;			// �뾶

public:
	Circle(const Point2D& c, int r) : center(c), radius(r) { }

	Point2D get_center() const { return center; }	// ��������

	int get_radius() const { return radius; }		// �뾶

	void print() const {							// ��ʾ
		std::cout << "�뾶[" << radius << "] ��������";  center.print();
	}
};

#endif
