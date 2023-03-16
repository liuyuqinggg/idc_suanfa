// ������

#include <cmath>
#include <string>
#include <iostream>

class Car {
	std::string name;			// ����
	int width, length, height;	// ��������������
	double xp, yp;				// ��ǰλ������
	double fuel_level;			// ʣ��ȼ��

public:
	//--- ���캯�� ---//
	Car(std::string n, int w, int l, int h, double f) {
		name = n;  width = w;  length = l;  height = h;  fuel_level = f;
		xp = yp = 0.0;
	}

	double x() { return xp; }				// ���ص�ǰλ�õ�X����
	double y() { return yp; }				// ���ص�ǰλ�õ�Y����

	double fuel() { return fuel_level; }	// ����ʣ��ȼ��

	void print_spec() {						// ��ʾ���
		std::cout << "���ƣ�" << name   << "\n"; 
		std::cout << "����" << width  << "mm\n"; 
		std::cout << "������" << length << "mm\n"; 
		std::cout << "���ߣ�" << height << "mm\n"; 
	}

	bool move(double dx, double dy) {	// ��X�����ƶ�dx����Y�����ƶ�dy
		double dist = sqrt(dx * dx + dy * dy);		// �ƶ�����

		if (dist > fuel_level)
			return false;				// ȼ�ϲ���
		else {
			fuel_level -= dist;			// �������ƶ�������Ӧ��ȼ��
			xp += dx;
			yp += dy;
			return true;
		}
	}
};
