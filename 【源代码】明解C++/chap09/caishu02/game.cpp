// ������Ϸ����2�棺��Ϸ���֣�

#include <ctime>
#include <cstdlib>
#include "caishu.h"

using namespace std;

static int answer = 0;

//--- ��ʼ�� ---//
void initialize()
{
	srand(time(NULL));
}

//--- �������⣨Ҫ�µ����� ---//
void gen_no()
{
	answer = rand() % (max_no + 1);
}

//--- �жϴ� ---//
int judge(int cand)
{
	if (cand == answer)		// ��ȷ��
		return 0;
	else if (cand > answer)	// ��
		return 1;
	else					// С
		return 2;
}
