// ��ʶ����IdNo����1�棺Դ�ļ���

#include "IdNo.h"

int IdNo::counter = 0;		// �Ѿ�����ı�ʶ������

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
