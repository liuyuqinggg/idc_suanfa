#ifndef ___Point2D
#define ___Point2D

#include <iostream>

//--- ����ʶ�ŵĶ�ά������ ---//
class Point2D {
	int xp, yp;					// X�����Y����
	int id_no;					// ��ʶ��
	static int counter;			// �Ѿ�����ı�ʶ��������������

public:
	Point2D(int x = 0, int y = 0);		// ���캯����������

	int id() const { return id_no; }	// ��ʶ��

	void print() const {				// ��ʾ����
		std::cout << "(" << xp << "," << yp << ")";
	}

	static int get_max_id();			// ���ر�ʶ�ŵ����ֵ��������
};

#endif
