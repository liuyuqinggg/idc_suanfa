// �����������ÿ������ʱ���ɲ�ͬ���������

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	srand(time(NULL));		// �ɵ�ǰʱ��ȷ������

	int x = rand();			// ���ɴ��ڵ���0��С�ڵ���RAND_MAX�������
	int y = rand();			// ���ɴ��ڵ���0��С�ڵ���RAND_MAX�������

	cout << "x��ֵ��" << x << "��y��ֵ��" << y << "��\n";
}
