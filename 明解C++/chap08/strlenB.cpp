//--- strlen��ʵ������B ---//

#include <cstddef>

size_t strlen(const char* s)
{
	const char* p = s;

	while (*s)
		s++;
	return s - p;
}
