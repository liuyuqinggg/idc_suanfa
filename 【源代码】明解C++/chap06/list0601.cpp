// ��������˵���ѧ��Ӣ�����߷ֲ���ʾ

#include <iostream>

using namespace std;

int main()
{
	int math[3];	// ��ѧ����
	int eng[3];		// Ӣ�����

	for (int i = 0; i < 3; i++) {	// �������
		cout << "[" << i + 1 << "] ";
		cout << "��ѧ��";		cin >> math[i];
		cout << "    Ӣ�";	cin >> eng[i];
	}

	int max_math = math[0];	  // ��ѧ��߷�
	if (math[1] > max_math) max_math = math[1];
	if (math[2] > max_math) max_math = math[2];

	int max_eng = eng[0];	  // Ӣ����߷�
	if (eng[1] > max_eng) max_eng = eng[1];
	if (eng[2] > max_eng) max_eng = eng[2];

	cout << "��ѧ��߷�Ϊ" << max_math << "��\n";
	cout << "Ӣ����߷�Ϊ" << max_eng  << "��\n";
}
