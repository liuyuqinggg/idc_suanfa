// ��ʶ����IdNo����1�棩��ʹ������

#include <iostream>
#include "IdNo.h"

using namespace std;

int main()
{
	IdNo a;		// ��1����ʶ��
	IdNo b;		// ��2����ʶ��
	IdNo c[4];	// ��3~6����ʶ��

	cout << "a�ı�ʶ�ţ�" << a.id() << '\n';
	cout << "b�ı�ʶ�ţ�" << b.id() << '\n';
	for (int i = 0; i < 4; i++)
		cout << "c[" << i << "]�ı�ʶ�ţ�" << c[i].id() << '\n';
}
