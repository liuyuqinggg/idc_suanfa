// ��ʾ���²�Ϊֱ�ǵĵ���ֱ�������Σ������棩

#include <iostream>

using namespace std;

//--- ������ʾn��'*' ---//
void put_stars(int n)
{
	while (n-- > 0)
		cout << '*';
}

int main()
{
	int n;

	cout << "��ʾ���²�Ϊֱ�ǵĵ���ֱ�������Ρ�\n";
	cout << "������";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		put_stars(i);
		cout << '\n';
	}
}
