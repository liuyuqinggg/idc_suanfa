// ������ֵ�еĽϴ�ֵ�ĺ���ģ�����ʽ������

#include <cstring>

//--- ��a��b�еĽϴ�ֵ ---//	 
template <class Type> Type maxof(Type a, Type b)
{
	return a > b ? a : b;
}

//--- ��a��b�еĽϴ�ֵ��const char*�͵���������---//
template <> const char* maxof<const char*>(const char* a, const char* b)
{
	return std::strcmp(a, b) > 0 ? a : b;
}
