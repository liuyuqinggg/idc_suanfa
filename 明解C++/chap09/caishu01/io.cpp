// ������Ϸ����1�棺����/������֣�

#include <iostream>

using namespace std;

extern int max_no;

//--- ��ʾ���� ---//
static void prompt()
{
	cout << "0~" << max_no << "������";
}

//--- ����� ---//
int input()
{
	int val;
	do {
		prompt();	// ��ʾ����
		cin >> val;
	} while (val < 0 || val > max_no);
	return val;
}

//--- ȷ���Ƿ���� ---//
bool confirm_retry()
{
	int cont;
	cout << "����һ�Σ�\n"
		 << "<Yes...1/No...0>��";
	cin >> cont;
	return static_cast<bool>(cont);
}
