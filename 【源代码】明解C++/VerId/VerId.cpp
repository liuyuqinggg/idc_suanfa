// ������֤�ı�ʶ����VerId��Դ�ļ���

#include "VerId.h"

int VerId::counter = 0;		// �Ѿ�����ı�ʶ������

//--- ���캯�� ---//
VerId::VerId()
{
	id_no = ++counter;		// �����ʶ��
}

//--- ���ر�ʶ�� ---//
int VerId::id() const
{
	return id_no;			// ���ر�ʶ��
}
