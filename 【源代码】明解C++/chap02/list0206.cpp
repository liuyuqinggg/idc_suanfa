// �ڶ��������ֵΪ��ʱ���ж���ż������ʾ�жϽ��

#include <iostream>

using namespace std;

int main()
{
	int n;

	cout << "����ֵ��";
	cin >> n;

	if (n > 0)
		if (n % 2 == 0)
			cout << "���ֵΪż����\n";
		else
			cout << "���ֵΪ������\n";
	else
		cout << "\a�����˷���ֵ��\n";
}
