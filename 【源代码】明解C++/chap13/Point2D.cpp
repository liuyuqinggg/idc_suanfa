#include "Point2D.h"

int Point2D::counter = 0;		// �Ѿ�����ı�ʶ�����������塿

//--- ���캯�������塿---//
Point2D::Point2D(int x, int y) : xp(x), yp(y) {
	id_no = ++counter;		// �����ʶ��
}

//--- ���ر�ʶ�ŵ����ֵ�����塿---//
int Point2D::get_max_id() {
	return counter;			// ���ر�ʶ�ŵ����ֵ
}
