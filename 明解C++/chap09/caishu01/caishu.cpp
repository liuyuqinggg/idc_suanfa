// ������Ϸ����1�棺��Ҫ���֣�

#include <iostream>

using namespace std;

void initialize();			//����ʼ�������ݵ�ǰʱ���������������
void gen_no();				//���������⡿�����������0~max_no��ֵ
int judge(int cand);		//���жϴ𰸡��ж�cand�Ƿ�Ϊ��ȷ��
int input();				//������𰸡�����0~max_no��ֵ
bool confirm_retry();		//��ȷ���Ƿ������ȷ���Ƿ�����һ��

int max_no = 9;		// Ҫ�µ��������ֵ

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
			else if (hantei == 2)
				cout << "\a�ٴ�һ�㡣\n";
		} while (panduan != 0);
		cout << "��ȷ�𰸡�\n";
	} while (confirm_retry());
}