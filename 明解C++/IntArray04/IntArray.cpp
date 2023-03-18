// ����������IntArray����4�棺Դ�ļ���

#include <cstddef>
#include "IntArray.h"

//--- ���ƹ��캯�� ---//
IntArray::IntArray(const IntArray& x)
{
	if (&x == this) { 						// �����ʼֵΪ�Լ�����
		nelem = 0;
		vec = NULL;
	} else {
		nelem = x.nelem;					// ʹԪ�ظ�����x��ͬ
		vec = new int[nelem];				// Ϊ�����������ռ�
		for (int i = 0; i < nelem; i++)		// ��������Ԫ��
			vec[i] = x.vec[i];
	}
}

//--- ��ֵ����� ---//
IntArray& IntArray::operator=(const IntArray& x)
{
	if (&x != this) {						// �����ֵԴ�����Լ�����
		if (nelem != x.nelem) {				// �����ֵǰ���Ԫ�ظ�����ͬ����
			delete[] vec;					// �ͷ�ԭ������Ŀռ�
			nelem = x.nelem;				// �µ�Ԫ�ظ���
			vec = new int[nelem];			// ���·���ռ�
		}
		for (int i = 0; i < nelem; i++)		// ��������Ԫ��
			vec[i] = x.vec[i];
	}
	return *this;
}
