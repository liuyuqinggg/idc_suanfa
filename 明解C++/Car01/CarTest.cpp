// �������ʹ������

#include <iostream>
#include "Car.h"

using namespace std;

int main()
{
	string name;
	int width, length, height;
	double gas;

	cout << "���������������ݡ�\n";
	cout << "���ƣ�";  cin >> name;
	cout << "����";  cin >> width;
	cout << "������";  cin >> length;
	cout << "���ߣ�";  cin >> height;
	cout << "��������";  cin >> gas;

	Car myCar(name, width, length, height, gas);

	myCar.print_spec();		// ��ʾ���

	while (true) {
		cout << "��ǰλ��(" << myCar.x() << ", " << myCar.y() << ")\n";
		cout << "ʣ��ȼ�ϣ�" << myCar.fuel() << '\n';
		cout << "�ƶ�[0...No/1...Yes]��";
		int move;
		cin >> move;
		if (move == 0) break;

		double dx, dy;
		cout << "X������ƶ����룺";  cin >> dx;
		cout << "Y������ƶ����룺";  cin >> dy;
		if (!myCar.move(dx, dy))
			cout << "\aȼ�ϲ��㣡\n";
	}
}
