// ���Բ��ң���2�棩

#include <iostream>

using namespace std;

//--- ������a��ǰn��Ԫ�������Բ���ֵkey����2�棩---//
int seq_search(int* a, int n, int key)
{
	int* p = a;

	while (n-- > 0) {
		if (*p == key)			// ���ҳɹ�
			return p - a;
		else
			p++;
	}
	return -1;					// ����ʧ��
}

int main()
{
	int key, idx;
	int x[7];
	int x_size = sizeof(x) / sizeof(x[0]);		// ����x��Ԫ�ظ���

	for (int i = 0; i < x_size; i++) {
		cout << "x[" << i << "] : ";
		cin >> x[i];
	}
	cout << "����ֵ��";
	cin >> key;

	if ((idx = seq_search(x, x_size, key)) != -1)
		cout << "���и�ֵ��Ԫ��Ϊx[" << idx << "]��\n";
	else
		cout << "û���ҵ���\n";
}
