// ��ʾbool�͵�ֵ

#include <iostream>

using namespace std;

int main()
{
	cout << true << ' ' << false << '\n';

	cout << boolalpha;				// ����ĸ��ʽ�������ֵ
	cout << true << ' ' << false << '\n';

	cout << noboolalpha;			// ����ֵ��ʽ�������ֵ
	cout << true << ' ' << false << '\n';
}
