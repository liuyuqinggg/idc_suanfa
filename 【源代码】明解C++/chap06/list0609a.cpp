// ��ʾ���²�Ϊֱ�ǵĵ���ֱ�������Σ������棩

#include <iostream>

using namespace std;

//--- ������ʾn���ַ�c ---//
void put_nchar(char c, int n)
{
	while (n-- > 0)
		cout << c;
}

//--- ������ʾn��'*' ---//
void put_stars(int n)
{
	put_nchar('*', n);		// ������ί�и�put_nchar
}

int main()
{
	int n;

	cout << "��ʾ���²�Ϊֱ�ǵĵ���ֱ�������Ρ�\n";
	cout << "������";
	cin >> n;

	for (int i = 1; i <= n; i++) {	// ��n��
		put_nchar(' ', n - i);		// ��ʾn-i��' '
		put_stars(i);				// ��ʾi��'*'
		cout << '\n';				// ����
	}
}
