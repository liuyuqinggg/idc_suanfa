// ��������˵���ѧ��Ӣ�����߷ֲ���ʾ�������棩

#include <iostream>

using namespace std;

//--- ����a��b��c�е����ֵ ---//
int max(int a, int b, int c)
{
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	return max;
}

int main()
{
	int math[3];	// ��ѧ
	int eng[3];		// Ӣ��

	for (int i = 0; i < 3; i++) {	// �������
		cout << "[" << i + 1 << "] ";
		cout << "��ѧ��";		cin >> math[i];
		cout << "    Ӣ�";	cin >> eng[i];
	}

	int max_math = max(math[0], math[1], math[2]);	// ��ѧ��߷�
	int max_eng  = max(eng[0],  eng[1],  eng[2]);	// Ӣ����߷�

	cout << "��ѧ��߷�Ϊ" << max_math << "��\n";
	cout << "Ӣ����߷�Ϊ" << max_eng  << "��\n";
}
