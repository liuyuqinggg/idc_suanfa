// �ֿ�����������ֵ�еĽϴ�ֵ�ĺ���ģ��ͺ���

#include <iostream>

using namespace std;

//--- ��ͨ������ע�⣺Ϊ����֤����Ϊ�����ؽ�Сֵ��---//
int maxof(int a, int b) { return a < b ? a : b; }

//--- ����ģ�� ---//
template <class Type> Type maxof(Type a, Type b) { return a > b ? a : b; }

int main()
{
	int a, b;

	cout << "����a��";	  cin >> a;
	cout << "����b��";	  cin >> b;

	cout << "�ϴ�ֵΪ" << maxof(a, b)      << "��\n";
	cout << "�ϴ�ֵΪ" << maxof<int>(a, b) << "��\n";
	cout << "�ϴ�ֵΪ" << maxof<>(a, b)    << "��\n";
}
