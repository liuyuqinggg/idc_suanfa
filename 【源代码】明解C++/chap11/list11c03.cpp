// ��ʾ��ǰ�����ں�ʱ��

#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	time_t current = time(NULL);				// ��ǰ����ʱ��
	struct tm* timer = localtime(&current);		// �ֽ�ʱ�䣨����ʱ�䣩
	char* wday_name[] = {"������", "����һ", "���ڶ�", "������", "������", "������", "������"};

	cout << "��ǰ���ں�ʱ����"
		 << timer->tm_year + 1900     << "��"
		 << timer->tm_mon + 1         << "��"
		 << timer->tm_mday            << "�գ�"
		 << wday_name[timer->tm_wday] << "��"
		 << timer->tm_hour            << "ʱ"
		 << timer->tm_min             << "��"
		 << timer->tm_sec             << "�롣\n";
}
