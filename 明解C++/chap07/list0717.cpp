// ��̬�����������󣨳�ʼ����

#include <iostream>

using namespace std;

int main()
{
	int* x = new int(5);		// ��������ӳ�ʼֵ

	cout << "*x = " << *x << '\n';

	delete x;					// ����
}
