// ����������ִ�мӷ����㣨��������������1000�ķ�Χ��ִ�У�

#include <iostream>

using namespace std;

int main()
{
	int n;			// Ҫ��ӵ������ĸ���
	cout << "������ִ�мӷ����㡣\n";
	cout << "Ҫ��ӵ������ĸ�����";
	cin >> n;

	int sum = 0;	// ������
	for (int i = 0; i < n; i++) {
		int t;
		cout << "������";
		cin >> t;
		if (sum + t > 1000) {
			cout << "\a������������1000��\n�������һ��������\n";
			break;
		}
		sum += t;
	}
	cout << "��������" << sum << "��\n";
}
