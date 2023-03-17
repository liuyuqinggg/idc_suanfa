#include <iostream>
using namespace std;

class SmartPtr {
    int* ptr; 
public:
    explicit SmartPtr(int* p = NULL) { ptr = p; }
    ~SmartPtr() { delete (ptr); }
    int& operator*() { return *ptr; }
};

int main()
{
    SmartPtr ptr(new int());
    *ptr = 20;
    cout << *ptr;
    return 0;
}

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vv16rj/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。