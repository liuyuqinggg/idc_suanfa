/*
	ʾ������
*/

#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	int a;			// a��int�ͱ���
	a = 1;			// ��ֵ���ڴ���������ֵ��
	int b = 5;		// ��ʼ�����ڴ�������ʱ��ֵ��

	srand(time(NULL));			// �������������
	int lucky = rand() % 10;	// 0~9�������
	cout << "���������������" << lucky << "��\n";
	cout << "����2������" <<   lucky / 2 << "��\n";
	cout << "����2��������" << lucky % 2 << "��\n";

	// �������󣨲������޸�ֵ�ı�����
	const double PI = 3.14;
	double r;
	cout << "�뾶��";
	cin >> r;
	cout << "�뾶" << r << "��Բ�������"
		 << (PI * r * r) << "��\n";

	string name;	// ����

	cout << "������";	// ��ʾ��������
	cin >> name;			// ���루�����ո�

	cout << "\a��"  "�ã�" << name << "��\n";
}
