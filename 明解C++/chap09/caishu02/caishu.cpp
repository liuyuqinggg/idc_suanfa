// ������Ϸ����2�棺��Ҫ���֣�

#include <iostream>
#include "caishu.h"

using namespace std;

int max_no = 9;			// Ҫ�µ��������ֵ

int main()
{
	initialize();		// ��ʼ��
	cout << "������Ϸ��ʼ��\n";

	do {
		gen_no();		// �������⣨Ҫ�µ�����
		int panduan;
		do {
			panduan = judge(input());	// �жϴ�
			if (panduan == 1)
				cout << "\a��Сһ�㡣\n";
			else if (panduan == 2)
				cout << "\a�ٴ�һ�㡣\n";
		} while (panduan != 0);
		cout << "��ȷ�𰸡�\n";
	} while (confirm_retry());
}
