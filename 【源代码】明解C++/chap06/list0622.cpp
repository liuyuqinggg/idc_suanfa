// �Զ��洢�ں;�̬�洢��

#include <iostream>

using namespace std;

int fx = 0;				// ��̬�洢��+�ļ�������

void func()
{
	static int sx = 0;	// ��̬�洢��+��������
	int 	   ax = 0;	// �Զ��洢��+��������

	fx++; sx++; ax++; 
	cout << fx << "  " << sx << "  " << ax << '\n';
}

int main()
{
	cout << "fx sx ax\n";
	cout << "--------\n";
	for (int i = 0; i < 8; i++)
		func();
}
