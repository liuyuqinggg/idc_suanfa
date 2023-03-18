#include <iostream>
#include "IntStack.h"

using namespace std;

int main()
{
	IntStack s1(5);		// ����Ϊ5��ջ
	s1.push(15);		// s1 = {15}
	s1.push(31);		// s1 = {15, 31}

	IntStack s2(1);		// ����Ϊ1��ջ
	s2 = s1;			// ��s1���Ƶ�s2��s2��������Ϊ5��
	s2.push(88);		// s2 = {15, 31, 88}

	IntStack s3 = s2;	// s3Ϊs2�ĸ���
	s3.push(99);		// s3 = {15, 31, 88, 99}

	cout << "ȡ��ջs3��ѹ���������ݡ�\n";
	while (!s3.empty())					// ��Ϊ���ڼ�
		cout << s3.pop() << '\n';		// ��ջ����ʾ
}
