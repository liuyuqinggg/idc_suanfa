// ����������IntArray����4�棺ͷ�ļ���

#ifndef ___Class_IntArray
#define ___Class_IntArray

//===== ���������� ======//
class IntArray {
	int nelem;		// �����Ԫ�ظ���
	int* vec;		// ָ���һ��Ԫ�ص�ָ��

public:
	//----- �±귶Χ���� -----//
	class IdxRngErr {
	private:
		const IntArray* ident;
		int idx;
	public:
		IdxRngErr(const IntArray* p, int i) : ident(p), idx(i) { }
		int index() const { return idx; }
	};

	//--- ��ʽ���캯�� ---//
	explicit IntArray(int size) : nelem(size) { vec = new int[nelem]; }

	//--- ���ƹ��캯�� ---//
	IntArray(const IntArray& x);

	//--- �������� ---//
	~IntArray() { delete[] vec; }

	//--- ����Ԫ�ظ��� ---//
	int size() const { return nelem; }

	//--- ��ֵ�����= ---//
	IntArray& operator=(const IntArray& x);

	//--- �±������ ---//
	int& operator[](int i) {
		if (i < 0 || i >= nelem)
			throw IdxRngErr(this, i);				// �׳��±귶Χ����
		return vec[i];
	}

	//--- const���±������ ---//
	const int& operator[](int i) const {
		if (i < 0 || i >= nelem)
			throw IdxRngErr(this, i);				// �׳��±귶Χ����
		return vec[i];
	}
};

#endif
