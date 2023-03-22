#include <iostream>       
#include <thread>        
#include <mutex>          

std::mutex mtx;     

void print_block (int n, char c) {
  mtx.lock();
  for (int i=0; i<n; ++i) { std::cout << c; }
  std::cout << '\n';
  mtx.unlock();
}

int main ()
{
  std::thread th1 (print_block,50,'*');
  std::thread th2 (print_block,50,'$');

  th1.join();
  th2.join();

  return 0;
}
/*
****************************************
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*/

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vdbzx5/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。