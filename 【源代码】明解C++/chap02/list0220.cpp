// �ж��Ƿ�Ϊ����

#include <iostream>

using namespace std;

int main()
{
	int y;

	cout << "��������ݣ�";
	cin >> y;

	cout << "������";
	if (y % 4 == 0 and y % 100 != 0 or y % 400 == 0)
		cout << "�����ꡣ\n";
	else
		cout << "�������ꡣ\n";
}
