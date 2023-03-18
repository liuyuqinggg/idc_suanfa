#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    volatile int ra = 0;
    int rb = 0;
    ra = 0x1111;
    ra = 0x2222;
    ra = 0x3333;
    rb = ra;
    printf("%d\n", ra);
    return 0;
}

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vwudo7/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。