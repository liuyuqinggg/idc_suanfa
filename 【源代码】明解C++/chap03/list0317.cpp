// ����������ִ�мӷ����㣨����0�������

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
		cout << "������Ϊ0���������";
		cin >> t;
		if (t == 0) break;		// ��for����˳�
		sum += t;
	}
	cout << "��������" << sum << "��\n";
}
