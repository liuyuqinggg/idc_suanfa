// ����������ֵ�еĽ�Сֵ�ͽϴ�ֵ����ʾ

#include <iostream>

using namespace std;

int main()
{
	int a, b;

	cout << "����a��";   cin >> a;
	cout << "����b��";   cin >> b;

	int min, max;		// ��Сֵ���ϴ�ֵ

	if (a < b) {		// ���aС��b
		min = a;
		max = b;
	} else {			// ����
		min = b;
		max = a;
	}

	cout << "��СֵΪ" << min << "��\n";
	cout << "�ϴ�ֵΪ" << max << "��\n";
}
