// ��ʾdouble�͵�����

#include <limits>
#include <iostream>

using namespace std;

int main()
{
	cout << "��Сֵ��" << numeric_limits<double>::min() << '\n';
	cout << "���ֵ��" << numeric_limits<double>::max() << '\n';
	cout << "β�����֣�" << numeric_limits<double>::radix  << "����"
					   << numeric_limits<double>::digits << "λ\n";
	cout << "λ����" << numeric_limits<double>::digits10 << '\n';
	cout << "��е��Сֵ��" << numeric_limits<double>::epsilon()<< '\n';
	cout << "����������" << numeric_limits<double>::round_error() << '\n';
	cout << "���뷽ʽ��";

	switch (numeric_limits<double>::round_style) {
	 case round_indeterminate:
						cout << "�޷�ȷ����\n"; break;
	 case round_toward_zero:
						cout << "��0���롣\n"; break;
	 case round_to_nearest:
						cout << "����Ϊ���Ա�ʾ�����ڽ���ֵ��\n"; break;
	 case round_toward_infinity:
						cout << "�����޴����롣\n"; break;
	 case round_toward_neg_infinity:
						cout << "�����޴����롣\n"; break;
	}
}
