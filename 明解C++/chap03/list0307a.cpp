// ������ֵ����������ʾ��Ӧ������+��-
// �ж�n����ż

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "��ʾ���ٸ��ַ���";
	cin >> n;

	if (n > 0) {
		int i = 1;
		while (i <= n) {
			if (i % 2)		// ����
				cout << '+';
			else			// ż��
				cout << '-';
			i++;
		}
		cout << '\n';
	}
}
