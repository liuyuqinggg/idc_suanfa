// ����������IntArray����3�棺ͷ�ļ���

#ifndef ___Class_IntArray
#define ___Class_IntArray

//===== ���������� ======//
class IntArray {
	int nelem;		// �����Ԫ�ظ���
	int* vec;		// ָ���һ��Ԫ�ص�ָ��

public:
	//--- ��ʽ���캯�� ---//
	explicit IntArray(int size) : nelem(size) { vec = new int[nelem]; }

	//--- ���ƹ��캯�� ---//
	IntArray(const IntArray& x);

	//--- �������� ---//
	~IntArray() { delete[] vec; }

	//--- ����Ԫ�ظ��� ---//
	int size() const { return nelem; }

	//--- ��ֵ����� ---//
	IntArray& operator=(const IntArray& x);

	//--- �±������ ---//
	int& operator[](int i) { return vec[i]; }

	//--- const���±������ ---//
	const int& operator[](int i) const { return vec[i]; }
};

#endif
