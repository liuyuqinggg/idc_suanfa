// ������Ϸ����һ��0~99������

#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));		// �������������

	int no = rand() % 100;	// Ҫ�µ���������һ��0~99�������
	int x;					// �Ӽ��̶����ֵ

	cout << "������Ϸ��ʼ!!\n";
	cout << "���һ��0~99������\n";

	do {
		cout << "��µ�����";
		cin >> x;

		if (x > no)
			cout << "\a��һ����С�����ɡ�\n";
		else if (x < no)
			cout << "\a��һ����������ɡ�\n";
	} while (x != no);

	cout << "��ȷ��\n";
}
