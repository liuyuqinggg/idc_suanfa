// ��ʾ���²�Ϊֱ�ǵĵ���ֱ��������

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "��ʾ���²�Ϊֱ�ǵĵ���ֱ�������Ρ�\n";
	cout << "������";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)	// ��ʾi��'*'
			cout << '*';
		cout << '\n';
	}
}
