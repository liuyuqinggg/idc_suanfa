// ���ݶ������ֵ��ʾ��ȭ���ƣ�ֻ����0��1��2��
// ʹ���߼��������!

#include <iostream>

using namespace std;

int main()
{
	int hand;

	do {
		cout << "��ѡ�����ƣ�0...ʯͷ 1...���� 2...������";
		cin >> hand;
	} while (!(hand >= 0 && hand <= 2));

	switch (hand) {
	 case 0: cout << "ʯͷ\n";	   break;
	 case 1: cout << "����\n";  	   break;
	 case 2: cout << "��\n";	       break;
	}
}
