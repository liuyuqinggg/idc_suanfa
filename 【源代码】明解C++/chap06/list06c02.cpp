// ������ƽ���͸�������ƽ��������ʽ�꣩

#include <iostream>

using namespace std;

#define sqr(x)  ((x) * (x))

int main()
{
	int    n;
	double x;

	cout << "������������";  cin >> n;
	cout << "������ƽ��Ϊ" << sqr(n) << "��\n";

	cout << "������ʵ����";  cin >> x;
	cout << "������ƽ��Ϊ" << sqr(x) << "��\n";
}
