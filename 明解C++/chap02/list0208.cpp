// �ж϶��������ֵ�Ƿ���2λ�����ϵ���

#include <iostream>

using namespace std;

int main()
{
	int n;

	cout << "����ֵ��";
	cin >> n;

	if (n <= -10 || n >= 10)				// 2λ������
		cout << "���ֵ��2λ�����ϵ�����\n";
	else									// ����2λ
		cout << "���ֵ�ǲ���2λ������\n";
}
