  #include <iostream>
  #include <cstring>
  using namespace std;
  int main(int argc, char * argv[])
  {
      int x = 4;
      char *s = "12345678";
      char *p = s;
      sizeof(x++);
      printf("%d\n", x);
    //   cout << strlen(++p) << "\n";
      cout << strlen(p++) << "\n";
      return 0;
  }

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vw9445/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。