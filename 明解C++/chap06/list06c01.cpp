// ���õݹ���ü���׳�

#include <iostream>

using namespace std;

//--- �ݹ����n�Ľ׳� ---//
int factorial(int n)
{
	if (n > 0)
		return n * factorial(n - 1);
	else
		return 1;
}

int main()
{
	int x;

	cout << "����ֵ��";
	cin >> x;

	cout << x << "�Ľ׳�Ϊ" << factorial(x) << "��\n";
}
