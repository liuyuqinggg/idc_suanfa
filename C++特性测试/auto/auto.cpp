#include <iostream>

using namespace std;

int main( )
{
    int count = 10;
    int& countRef = count;
    auto myAuto = countRef;
    // auto& myAuto = countRef;

    countRef = 11;
    cout << count << " ";

    myAuto = 12;
    cout << count << endl;
}
// 11
// 11

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vw6ybe/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。