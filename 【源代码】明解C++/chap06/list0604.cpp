// ����������ֵ�еĽϴ�ֵ�������棩

#include <iostream>

using namespace std;

//--- ����a��b�еĽϴ�ֵ ---//
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	int a, b;

	cout << "����a��";   cin >> a;
	cout << "����b��";   cin >> b;

	cout << "�ϴ�ֵΪ" << max(a, b) << "��\n";
}
