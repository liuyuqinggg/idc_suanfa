// �����ʵ��ֵ���Ա�10������

#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	double x;

	cout << "ʵ��ֵ��";
	cin >> x;

	if (double m = fmod(x, 10)) {
		cout << "���ֵ�����Ա�10������\n";
		cout << "����Ϊ" << m << "��\n";
	} else {
		cout << "���ֵ���Ա�10������\n";
	}
}
