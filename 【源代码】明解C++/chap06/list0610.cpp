// ��ʾ�����κͳ�����

#include <iostream>

using namespace std;

//--- ������ʾn���ַ�c ---//
void put_nchar(char c, int n)
{
	while (n-- > 0)
		cout << c;
}

//--- �����ַ�c������ʾ�߳�Ϊn�������� ---//
void put_square(int n, char c)
{
	for (int i = 1; i <= n; i++) {		// ��n��
		put_nchar(c, n);				// ��ʾn���ַ�c
		cout << '\n';					// ����
	}
}

//--- �����ַ�c������ʾ��Ϊh�ҿ�Ϊw�ĳ����� ---//
void put_rectangle(int h, int w, char c)
{
	for (int i = 1; i <= h; i++) {		// ��h��
		put_nchar(c, w);				// ��ʾw���ַ�c
		cout << '\n';					// ����
	}
}

int main()
{
	int n, h, w;

	cout << "��ʾ�����Ρ�\n";
	cout << "�߳���";   cin >> n;

	put_square(n, '*');			// ��'*'��ʾ�߳�Ϊn��������

	cout << "��ʾ�����Ρ�\n";
	cout << "�ߣ�";   cin >> h;
	cout << "��";   cin >> w;

	put_rectangle(h, w, '+');	// ��'+'��ʾ��Ϊh�ҿ�Ϊw�ĳ�����
}
