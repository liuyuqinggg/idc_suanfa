// ��������Counter����2�棩

#ifndef ___Class_Counter
#define ___Class_Counter

#include <climits>

//===== �������� =====//
class Counter {
	unsigned cnt;		// ������

public:
	//--- ���캯�� ---//
	Counter() : cnt(0) { }

	//--- unsigned�͵�ת������  ---//
	operator unsigned() const { return cnt; }

	//--- �߼�������� ---//
	bool operator!() const { return cnt == 0; }

	//--- ǰ�õ�������� ---//
	Counter& operator++() {
		if (cnt < UINT_MAX) cnt++;	// ������������ΪUINT_MAX
		return *this;				// �������������
	}

	//--- ���õ�������� ---//
	Counter operator++(int) {
		Counter x = *this;			// �������ǰ��ֵ
		++(*this);					// ��ǰ�õ��������ִ�е���
		return x;					// ���ظղű����ֵ
	}

	//--- ǰ�õݼ������ ---//
	Counter& operator--() {
		if (cnt > 0) cnt--;			// ������������Ϊ0
		return *this;				// �������������
	}

	//--- ���õݼ������ ---//
	Counter operator--(int) {
		Counter x = *this;			// ����ݼ�ǰ��ֵ
		--(*this);					// ��ǰ�õݼ������ִ�еݼ�
		return x;					// ���ظղű����ֵ
	}
};

#endif
