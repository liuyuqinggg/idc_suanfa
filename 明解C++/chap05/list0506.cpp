// ����5���˵ķ�������ʾ�ֺܷ�ƽ����

#include <iostream>

using namespace std;

int main()
{
	const int number = 5    //����
	int score[number];		// number���˵ķ���
	int sum = 0;		// �ܷ�

	cout << "����"<<number<<"���˵��ֺܷ�ƽ���֡�\n";
	for (int i = 0; i < number; i++) {
		cout << "��" << i + 1 << "���˵ķ�����";
		cin >> score[i];		// ����score[i]
		sum += score[i];		// ��score[i]�ӵ�sum��
	}

	cout << "�ܷ�Ϊ" << sum << "��\n";
	cout << "ƽ����Ϊ" << static_cast<double>(sum) / 5 << "��\n";
}
