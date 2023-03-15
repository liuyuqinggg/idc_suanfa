// ���������ռ��using����

#include <iostream>

using namespace std;

namespace English {

	int x = 1;

	void print_x()
	{
		cout << "The value of x is " << x << ".\n";
	}

	void hello()
	{
		cout << "Hello!\n";
	}
}

namespace Chinese {

	int x = 2;

	void print_x()
	{
		cout << "����x��ֵΪ" << x << "��\n";
	}

	void hello()
	{
		cout << "��ã�\n";
	}
}

int main()
{
	using Chinese::hello;	// ����Chinese�����ռ��ʹ��

	cout << "English::x = " << English::x << '\n';
	cout << "Chinese::x = " << Chinese::x << '\n';

	English::hello();
	hello();				// ����ҪChinese::
}
