// ������ֵ����ʾ��Ӧ������*��for��䣩

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "��ʾ���ٸ���";
	cin >> n;

	if (n > 0) {
		for (int i = 1; i <= n; i++)
			cout << '*';
		cout << '\n';
	}
}
