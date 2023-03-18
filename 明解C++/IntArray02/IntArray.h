// ����������IntArray����2�棩

#ifndef ___Class_IntArray
#define ___Class_IntArray

//===== ���������� ======//
class IntArray {
	int nelem;		// �����Ԫ�ظ���
	int* vec;		// ָ���һ��Ԫ�ص�ָ��

public:
	//--- ��ʽ���캯�� ---//
	explicit IntArray(int size) : nelem(size) { vec = new int[nelem]; }

	//--- �������� ---//
	~IntArray() { delete[] vec; }

	//--- ����Ԫ�ظ��� ---//
	int size() const { return nelem; }

	//--- �±������ ---//
	int& operator[](int i) { return vec[i]; }
};

#endif
