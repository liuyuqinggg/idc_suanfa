// ������֤�ı�ʶ����VerId��ͷ�ļ���

#ifndef ___Class_VerId
#define ___Class_VerId

//===== ��ʶ���� =====//
class VerId {
	int id_no;				// ��ʶ��

public:
	static int counter;		// �Ѿ�����ı�ʶ������

	VerId();				// ���캯��

	int id() const;			// ���ر�ʶ��
};

#endif
