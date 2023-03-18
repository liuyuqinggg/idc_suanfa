#include <iostream>


int main()
{
#if __has_include("vector")
    printf("c program\n");
#endif

#if __has_include("iostream")
    std::cout << "c++ program\n" << std::endl;
#endif

    return 0;
}

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vvcier/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。