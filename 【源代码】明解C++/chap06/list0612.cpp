// ���������ĺ�����Ĭ��ʵ�Σ�

#include <iostream>

using namespace std;

//--- ����n�ξ��� ---//
void alerts(int n = 3)
{
	while (n-- > 0)
		cout << '\a';
}

int main()
{
	alerts();
	cout << "������\n";

	alerts(5);
	cout << "�ٴξ�����\n";
}
