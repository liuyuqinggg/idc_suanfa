// �������õĺ���

#include <iostream>

using namespace std;

//--- ����x������ ---//
int& ref()
{
	static int x;	// ��̬�洢��
	return x;
}

int main()
{
	ref() = 5;									// ��ref()��ֵ
	cout << "ref() = " << ref() << '\n';		// ��ʾref()��ֵ
}
