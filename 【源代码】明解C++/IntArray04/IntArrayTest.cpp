// ����������IntArray����4�棩��ʹ������

#include <new>
#include <iostream>
#include "IntArray.h"

using namespace std;

//--- ��Ԫ�ظ���Ϊsize�������ǰnum�����ݸ�ֵ����ʾ --//
void f(int size, int num)
{
	try {
		IntArray x(size);
		for (int i = 0; i < num; i++) {
			x[i] = i;
			cout << "x[" << i << "] = " << x[i] << '\n';
		}
	}

	catch (IntArray::IdxRngErr& x) {
		cout << "�±������" << x.index() << '\n';
		return;
	}

	catch (bad_alloc) {
		cout << "�ڴ����ʧ�ܡ�\n";
		exit(1);				// ǿ�ƽ���
	}
}

int main()
{
	int size, num;

	cout << "Ԫ�ظ�����";
	cin >> size;

	cout << "���ݸ�����";
	cin >> num;

	f(size, num);

	cout << "main����������\n";
}
