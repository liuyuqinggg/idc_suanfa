// ���������ֵ���Ա�10������

#include <iostream>

using namespace std;

int main()
{
	int n;

	cout << "����ֵ��";
	cin >> n;

	if (int mod = n % 10) {
		cout << "���ֵ�����Ա�10������\n";
		cout << "����Ϊ" << mod << "��\n";
	} else {
		cout << "���ֵ���Ա�10������\n";
	}
}
