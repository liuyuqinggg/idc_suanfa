// ��ʶ����IdNo����1�棺ͷ�ļ���

#ifndef ___Class_IdNo
#define ___Class_IdNo

//===== ��ʶ���� =====//
class IdNo {
	static int counter;		// �Ѿ�����ı�ʶ������
	int id_no;				// ��ʶ��

public:
	IdNo();					// ���캯��

	int id() const;			// ���ر�ʶ��
};

#endif
