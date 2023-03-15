// ����������ֵ�����ذ棩

#include <iostream>

using namespace std;

//--- ����Ԫ�ظ���Ϊn������x�����ֵ��int�棩---//
int maxof(const int x[], int n)
{
	int max = x[0];
	for (int i = 1; i < n; i++)
		if (x[i] > max)
			max = x[i];
	return max;
}

//--- ����Ԫ�ظ���Ϊn������x�����ֵ��double�棩---//
double maxof(const double x[], int n)
{
	double max = x[0];
	for (int i = 1; i < n; i++)
		if (x[i] > max)
			max = x[i];
	return max;
}

int main()
{
	const int isize = 8;	// ����ix��Ԫ�ظ���
	int ix[isize];			// int������

	// ������������ֵ
	cout << "������" << isize << "��������\n";
	for (int i = 0; i < isize; i++) {
		cout << i + 1 << "��";
		cin >> ix[i];
	}
	cout << "���ֵΪ" << maxof(ix, isize) << "��\n\n";

	const int dsize = 5;	// ����dx��Ԫ�ظ���
	double dx[dsize];		// double������

	// ʵ����������ֵ
	cout << "������" << dsize << "��ʵ����\n";
	for (int i = 0; i < dsize; i++) {
		cout << i + 1 << "��";
		cin >> dx[i];
	}
	cout << "���ֵΪ" << maxof(dx, dsize) << "��\n";
}
