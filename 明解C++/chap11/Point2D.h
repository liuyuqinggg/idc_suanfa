#ifndef ___Point2D
#define ___Point2D

//--- ��ά������ ---//
class Point2D {
	int xp, yp;		// X�����Y����

public:
	Point2D(int x = 0, int y = 0) : xp(x), yp(y) { }

	int x() const { return xp; }				// X����
	int y() const { return yp; }				// Y����

	void print() const { std::cout << "(" << xp << "," << yp << ")"; } // ��ʾ
};

#endif
