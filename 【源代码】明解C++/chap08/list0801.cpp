// ��ʾ�ַ��������������ͺʹ�С

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
	cout << "�ַ���������\"ABC\"\n";
	cout << "  ���ͣ�"     << typeid("ABC").name()
		 << "  ��С��" << sizeof("ABC") << "\n\n";

	cout << "�ַ���������\"\"\n";
	cout << "  ���ͣ�"     << typeid("").name()
		 << "  ��С��" << sizeof("") << "\n\n";

	cout << "�ַ���������\"ABC\\0DEF\"\n";
	cout << "  ���ͣ�"     << typeid("ABC\0DEF").name()
		 << "  ��С��" << sizeof("ABC\0DEF") << "\n";
}
