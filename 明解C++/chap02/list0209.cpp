// ��ʾ������·������ļ���

#include <iostream>

using namespace std;

int main()
{
	int month;

	cout << "�жϼ��ڡ�\n�·ݣ�";
	cin >> month;

	if (month >= 3 && month <= 5)		// 3�� 4�� 5��
		cout << "���Ǵ�����\n";
	else if (month >= 6 && month <= 8)	// 6�� 7�� 8��
		cout << "�����ļ���\n";
	else if (month >= 9 && month <= 11)	// 9�� 10�� 11��
		cout << "�����＾��\n";
	else if (month == 12 || month == 1 || month == 2)	// 12�� 1�� 2��
		cout << "���Ƕ�����\n";

	else
		cout << "\aû������·ݡ�\n";
}
