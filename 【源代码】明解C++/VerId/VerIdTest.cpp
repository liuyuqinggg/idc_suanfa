// ������֤�ı�ʶ����VerId��ʹ������

#include <iostream>
#include "VerId.h"

using namespace std;

int main()
{
	VerId a;		// ��1����ʶ��
	VerId b;		// ��2����ʶ��

	cout << "a�ı�ʶ�ţ�" << a.id() << '\n';
	cout << "b�ı�ʶ�ţ�" << b.id() << '\n';
	cout << "�����Ķ���ĸ�����" << VerId::counter << '\n';
	cout << "�����Ķ���ĸ�����" << a.counter << '\n';
	cout << "�����Ķ���ĸ�����" << b.counter << '\n';
}
