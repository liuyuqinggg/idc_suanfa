// ����5���˵ķ�������ʾ�ֺܷ�ƽ����

#include <iostream>

using namespace std;

int main()
{
	int wangming, liyang, zhanghong, zhaogang, zhouyan;	// ����
	int sum = 0;		// �ܷ�

	cout << "����5���˵��ֺܷ�ƽ���֡�\n";
	cout << "��1���˵ķ�����";   cin >> wangming;    sum += wangming;
	cout << "��2���˵ķ�����";   cin >> liyang;    sum += liyang;
	cout << "��3���˵ķ�����";   cin >> zhanghong;  sum += zhanghong;
	cout << "��4���˵ķ�����";   cin >> zhaogang;   sum += zhaogang;
	cout << "��5���˵ķ�����";   cin >> zhouyan;    sum += zhouyan;

	cout << "�ܷ�Ϊ" << sum << "��\n";
	cout << "ƽ����Ϊ" << static_cast<double>(sum) / 5 << "��\n";
}
