// ��ʽʵ����������ֵ�еĽϴ�ֵ�ĺ���ģ��

#include <iostream>

using namespace std;

//--- ��a��b�еĽϴ�ֵ ---//
template <class Type> Type maxof(Type a, Type b)
{
	return a > b ? a : b;
}

int main()
{
	int a, b;
	double x;

	cout << "����a��";	  cin >> a;
	cout << "����b��";	  cin >> b;
	cout << "ʵ��x��";	  cin >> x;

	cout << "a��b�еĽϴ�ֵΪ" << maxof(a, b)         << "��\n";
	cout << "a��x�еĽϴ�ֵΪ" << maxof<double>(a, x) << "��\n";
}
