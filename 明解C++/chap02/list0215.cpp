// �������������н�������

#include <iostream>

using namespace std;

int main()
{
	int a, b;

	cout << "����a��";   cin >> a;
	cout << "����b��";   cin >> b;

	if (a == b) {
		cout << "����ֵ��ȡ�\n";
	} else {
		if (a < b) {		// ��aС��bʱ
		int t = a;		// �������ǵ�ֵ
			a = b;
			b = t;
		}
		cout << "��a>b����\n";
	cout << "����aΪ" << a << "��\n";
	cout << "����bΪ" << b << "��\n";
	}
}
