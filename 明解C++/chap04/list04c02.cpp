// �жϼ��ַ������з����ַ��ͻ����޷����ַ���

#include <limits>
#include <iostream>

using namespace std;

int main()
{
	cout << "�ô���ϵͳ�ļ��ַ�����"
		 <<	(numeric_limits<char>::is_signed ? "�з���" : "�޷���")
		 <<	"�ַ��͡�\n";
}
