// ��������Counter����1�棩

#ifndef ___Class_Counter
#define ___Class_Counter

#include <climits>

//===== �������� =====//
class Counter {
	unsigned cnt;		// ������

public:
	//--- ���캯�� ---//
	Counter() : cnt(0) { }

	//--- ���ϼ��� ---//
	void increment() {
		if (cnt < UINT_MAX) cnt++;		// ������������ΪUINT_MAX
	}

	//--- ���¼��� ---//
	void decrement() {
		if (cnt > 0) cnt--;				// ������������Ϊ0
	}

	//--- ���ؼ����� ---//
	unsigned value() {					// cnt�Ļ�ȡ��
		return cnt;
	}
};

#endif
