//--- ��Ա���ʹ������ ---//

#include <iostream>
#include "Member.h"

using namespace std;

void print(Member* p)
{
	p->print();			// ���ó�Ա����print
}

int main()
{
	Member wangming("����", 15, 4);			// ���ù��캯��
	wangming.set_rank(wangming.get_rank() + 1);		// �ȼ�����1
	print(&wangming);								// ��ʾ
}
