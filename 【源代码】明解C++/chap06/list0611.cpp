// ����ѵ��

#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

//--- ȷ���Ƿ���� ---//
bool confirm_retry()
{
	int retry;
	do {
		cout << "����һ�Σ�<Yes...1/No...0>:";
		cin >> retry;
	} while (retry != 0 && retry != 1);
	return static_cast<bool>(retry);		// ����ת��Ϊbool�ͺ��ֵ
}

int main()
{
	srand(time(NULL));
	cout << "����ѵ����ʼ!!\n";

	do {
		int x = rand() % 900 + 100;		// ��λ��
		int y = rand() % 900 + 100;		// ��λ��
		int z = rand() % 900 + 100;		// ��λ��

		while (true) {
			int k;						// �����ֵ
			cout << x << " + " << y << " + " << z << " = ";
			cin >> k;
			if (k == x + y + z)			// ��ȷ��
				break;
			cout << "\a����!!\n";
		}
	} while (confirm_retry());
}
