// ��ʶ����IdNo����2�棩��ʹ������

#include <iostream>
#include "IdNo.h"

using namespace std;

int main()
{
	IdNo a;		// ��1����ʶ��
	IdNo b;		// ��2����ʶ��

	cout << "a�ı�ʶ�ţ�" << a.id() << '\n';
	cout << "b�ı�ʶ�ţ�" << b.id() << '\n';
	cout << "Ŀǰ�Ѿ�����ı�ʶ�ŵ����ֵ��" << IdNo::get_max_id() << '\n';
}
