// ���ݶ������ֵ��ʾ��ȭ����

#include <iostream>

using namespace std;

int main()
{
	int hand;

	cout << "��ѡ�����ƣ�0...ʯͷ 1...���� 2...������";
	cin >> hand;

	switch (hand) {
	 case 0: cout << "ʯͷ\n";	   break;
	 case 1: cout << "����\n";   break;
	 case 2: cout << "��\n";	   break;
	}
}
