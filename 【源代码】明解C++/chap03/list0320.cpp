// ����������ִ�мӷ����㣨����9999��ǿ�ƽ�����

#include <iostream>

using namespace std;

int main()
{
	int n;			// Ҫ��ӵ������ĸ���
	cout << "������ִ�мӷ����㡣\n";
	cout << "Ҫ��ӵ������ĸ�����";
	cin >> n;
	cout << "����9999��ǿ�ƽ�����\n";

	int sum = 0;	// ������
	for (int i = 0; i < n; i++) {
		int t;
		cout << "������";
		cin >> t;
		if (t == 9999)
			goto Exit;
		sum += t;
	}
	cout << "��������" << sum << "��\n";

Exit:
	;
}
