// ��ʾ������·������ļ���

#include <iostream>

using namespace std;

int main()
{
	int month;

	cout << "�жϼ��ڡ�\n�·ݣ�";
	cin >> month;

	if (month < 1 || month > 12)
		cout << "\aû������·ݡ�\n";
	else if (month <= 5)						//  3�� 4�� 5��
		cout << "���Ǵ�����\n";
	else if (month <= 8)						//  6�� 7�� 8��
		cout << "�����ļ���\n";
	else if (month <= 11)						//  9�� 10�� 11��
		cout << "�����＾��\n";
	else										// 12�� 1�� 2��
		cout << "���Ƕ�����\n";
}
