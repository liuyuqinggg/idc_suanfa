// ��̬������������

#include <iostream>

using namespace std;

int main()
{
	int* x = new int;			// ����������洢�ռ䣩

	cout << "������";
	cin >> *x;

	cout << "*x = " << *x << '\n';

	delete x;					// ���٣��ͷŴ洢�ռ䣩
}
