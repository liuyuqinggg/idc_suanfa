// �쳣���׳��Ͳ���

#include <new>
#include <iostream>

using namespace std;

//=== ����� ===//
class OverFlow { };

//--- ����x��2�� ---//
int f(int x)
{
	if (x < 0)
		throw "��֡�ֵΪ����\n";
	else if (x > 30000)
		throw OverFlow();
	else
		return 2 * x;
}

int main()
{
	int a;
	cout << "������";
	cin >> a;

	try {
		int b = f(a);
		cout << "������2��Ϊ" << b << "��\n";
	}
	catch (const char* str) {		// �����ַ������쳣
		cout << "�����쳣��" << str;
	}
	catch (OverFlow) {				// ���ﲶ��OverFlow�͵��쳣
		cout << "�����������������\n";
		return 1;
	}
}
