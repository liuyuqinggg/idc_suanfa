// ѭ����̬����������������쳣������

#include <cstddef>
#include <iostream>

using namespace std;

int main()
{
	cout << "ѭ������Ԫ�ظ���Ϊ30000��double�����顣\n";

	while (true) {
		double* a = new(nothrow) double[30000];		// �����������쳣������

		if (a == NULL) {
			cout << "���鴴��ʧ�ܣ������жϡ�\n";
			return 1;
		}
	}
}
