#include <stdio.h>
#include <string.h>
#include <assert.h>
void *memmove(void *dst, const void *src, size_t size)
{
    char *psrc;
    char *pdst;

    if (NULL == dst || NULL == src)
    {
        return NULL;
    }

    if ((src < dst) && (char *)src + size > (char *)dst) // 出现地址重叠的情况，自后向前拷贝
    {
        psrc = (char *)src + size - 1;
        pdst = (char *)dst + size - 1;
        while (size--)
        {
            *pdst-- = *psrc--;
        }
    }
    else
    {
        psrc = (char *)src;
        pdst = (char *)dst;
        while (size--)
        {
            *pdst++ = *psrc++;
        }
    }

    return dst;
}

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vwqxfc/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
void* My_memmove(void* dest , const void* src, size_t num)
{
	assert(dest && src);
	if (dest < src)
	{
		while (num--)//前->后
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		while (num--)//后->前
		{
			*((char*)dest+num) = *((char*)src + num);
		}
	}
	return NULL;
}
int main()
{
	char str[] = "memmove can be very useful......";
	memmove(str + 15, str + 20, 11);
	// My_memmove(str + 20, str + 15, 11);
	puts(str);
	return 0;
}