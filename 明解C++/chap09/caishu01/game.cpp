// ������Ϸ����1�棺��Ϸ���֣�

#include <ctime>
#include <cstdlib>

using namespace std;

static int answer = 0;
extern int max_no;

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
