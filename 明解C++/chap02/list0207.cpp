// �ж϶��������ֵ��λ����0��1λ����2λ�����ϵ�����

#include <iostream>

using namespace std;

int main()
{
	int n;

	cout << "����ֵ��";
	cin >> n;

	if (n == 0)								// 0
		cout << "���ֵ��0��\n";
	else if (n >= -9 && n <= 9)				// 1λ��
		cout << "���ֵ��1λ����\n";
	else									// 2λ�����ϵ���
		cout << "���ֵ��2λ�����ϵ�����\n";
}
