// �������һ��0~9���������ֲ���ʾ

#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));				// �������������

	int lucky = rand() % 10;		// 0~9�������

	cout << "���������������" << lucky << "��\n";
}