// ����ߵ����ֵ�����ص����ֵ

#include <iostream>

using namespace std;

//--- ����Ԫ�ظ���Ϊn������a�����ֵ ---//
int maxof(const int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

int main()
{
	const int number = 5;				// ����
	int height[number], weight[number];	// ��ߡ�����

	cout << "������" << number << "���˵���ߺ����ء�\n";
	for (int i = 0; i < number; i++) {
		cout << "��" << i + 1 << "���˵���ߣ�";
		cin >> height[i];
		cout << "��" << i + 1 << "���˵����أ�";
		cin >> weight[i];
	}
	int hmax = maxof(height, number);	// ��ߵ����ֵ
	int wmax = maxof(weight, number);	// ���ص����ֵ

	cout << "��ߵ����ֵ��" << hmax << "cm\n";
	cout << "���ص����ֵ��" << wmax << "kg\n";
}
