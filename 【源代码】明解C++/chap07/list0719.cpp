// ѭ����̬������������쳣����

#include <new>
#include <iostream>

using namespace std;

int main()
{
	cout << "ѭ������Ԫ�ظ���Ϊ30000��double�����顣\n";

	while (true) {
		try {
			double* a = new double[30000];	// ����
		}
		catch (bad_alloc) {
			cout << "���鴴��ʧ�ܣ������жϡ�\n";
			return 1;
		}
	}
}
