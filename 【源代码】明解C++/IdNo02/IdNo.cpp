// ��ʶ����IdNo����2�棺Դ�ļ���

#include "IdNo.h"

int IdNo::counter = 0;

//--- ���캯�� ---//
IdNo::IdNo()
{
	id_no = ++counter;		// �����ʶ��
}

//--- ���ر�ʶ�� ---//
int IdNo::id() const
{
	return id_no;			// ���ر�ʶ��
}

//--- ���ر�ʶ�ŵ����ֵ ---//
int IdNo::get_max_id()
{
	return counter;			// ���ر�ʶ�ŵ����ֵ
}
