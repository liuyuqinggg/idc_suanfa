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
void put_square(int n, char c = '*')
{
	for (int i = 1; i <= n; i++) {		// ��n��
		put_nchar(c, n);				// ��ʾn���ַ�c
		cout << '\n';					// ����
	}
}

//--- �����ַ�c������ʾ��Ϊh�ҿ�Ϊw�ĳ����� ---//
void put_rectangle(int h, int w, char c = '*')
{
	for (int i = 1; i <= h; i++) {		// ��h��
		put_nchar(c, w);				// ��ʾw���ַ�c
		cout << '\n';					// ����
	}
}

int main()
{
	put_square(5, '+');			// ����'+'���γɵı߳�Ϊ5��������
	put_square(5);				// ����'*'���γɵı߳�Ϊ5��������
	put_rectangle(4, 3, '-');	// ����'-'���γɵ�4��3�еĳ�����
	put_rectangle(4, 3);		// ����'*'���γɵ�4��3�еĳ�����
}
