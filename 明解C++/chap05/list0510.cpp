// ��3��2�еĶ�ά��������й���Ԫ�ض���ֵ����ʾ

#include <iostream>

using namespace std;

int main()
{
	int m[3][2];	// 3��2�еĶ�ά����

	cout << "�Ը�����Ԫ�ظ�ֵ��\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "m[" << i << "][" << j << "]��";
			cin >> m[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "m[" << i << "][" << j << "]��" << m[i][j] << '\n';
		}
	}
}
