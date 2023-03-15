#ifndef ___IntStack
#define ___IntStack

#include <iostream>

//--- ����ջ�� ---//
class IntStack {
	int nelem;		// ջ�������������Ԫ�ظ�����
	int* stk;		// ָ���һ��Ԫ�ص�ָ��
	int ptr;		// ջָ�루��ǰ��ѹ�����ݸ�����

public:
	//--- ��ʽ���캯�� ---//
	explicit IntStack(int sz) : nelem(sz), ptr(0) { stk = new int[nelem]; }

	IntStack(const IntStack& x) {			  //--- ���ƹ��캯�� ---//
		nelem = x.nelem;						// ʹ������x��ͬ
		ptr = x.ptr;							// ��ʼ��ջָ��
		stk = new int[nelem];					// Ϊ�����������ռ�
		for (int i = 0; i < nelem; i++)			// ��������Ԫ��
			stk[i] = x.stk[i];
	}

	~IntStack() { delete[] stk; }			  //--- �������� ---//

	int size() const { return nelem; }		  //--- �������� ---//

	bool empty() const { return ptr == 0; }	  //--- ջΪ�գ� ---//

	IntStack& operator=(const IntStack& x) {  //--- ��ֵ�����= ---//
		if (&x != this) {						// �����ֵԴ�����Լ�����
			if (nelem != x.nelem) {				// �����ֵǰ���Ԫ�ظ�����ͬ����
				delete[] stk;					// �ͷ�ԭ������Ŀռ�
				nelem = x.nelem;				// �µ�����
				ptr = x.ptr;					// �µ�ջָ��
				stk = new int[nelem];			// ���·���ռ�
			}
			for (int i = 0; i < ptr; i++)		// ���ƻ�ѹ��Ԫ��
				stk[i] = x.stk[i];
		}
		return *this;
	}

	//--- ѹջ����ĩβѹ������ ---//
	void push(int x) { if (ptr < nelem) stk[ptr++] = x; }

	//--- ��ջ����ĩβȡ����ѹ������ ---//
	int pop() { if (ptr > 0) return stk[--ptr]; else throw 1; }
};

#endif
