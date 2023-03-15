// ����ֵ��Boolean

#ifndef ___Class_Boolean
#define ___Class_Boolean

#include <iostream>

//===== ����ֵ�� =====//
class Boolean {
public:
	enum boolean {False, True};			// FalseΪ�٣�TrueΪ��

private:
	boolean v;			// ����ֵ

public:
	// Ĭ�Ϲ��캯��
	Boolean() : v(False) { }		// ��ʼ��Ϊ��

	// ���캯��
	Boolean(int val) : v(val == 0 ? False : True) { }

	// int�͵�ת������
	operator int() const { return v; }

	// const char*�͵�ת������
	operator const char*() const { return v == False ? "False" : "True"; }
};

//--- �������s����x ---//
inline std::ostream& operator<<(std::ostream& s, Boolean& x)
{
	return s << static_cast<const char*>(x);
}

#endif
