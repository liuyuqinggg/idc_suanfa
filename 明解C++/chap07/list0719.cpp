// ѭ����̬������������쳣����

#include <new>
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
	cout << "ѭ������Ԫ�ظ���Ϊ30000��double�����顣\n";
	int count = 0;
	cout << sizeof(double);
	sleep(1);
	while (true) {
		try {
			double* a = new double[30000];	// ����
			cout << ++count << endl;
		}
		catch (bad_alloc) {
			cout << "���鴴��ʧ�ܣ������жϡ�\n";
			return 1;
		}
	}
}
