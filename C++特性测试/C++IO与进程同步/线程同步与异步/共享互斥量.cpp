#include <iostream>
#include <mutex>  // For std::unique_lock
#include <shared_mutex>
#include <thread>
 
class ThreadSafeCounter {
 public:
  ThreadSafeCounter() = default;
 
  // 多个线程可以同时读取 countter 计数
  unsigned int get() const {
    std::shared_lock lock(mutex_);
    return value_;
  }
 
  // 只有1个线程可以修改 countter 计数
  void increment() {
    std::unique_lock lock(mutex_);
    value_++;
  }
 
  // 只有1个线程可以修改 countter 计数
  void reset() {
    std::unique_lock lock(mutex_);
    value_ = 0;
  }
 
 private:
  mutable std::shared_mutex mutex_;
  unsigned int value_ = 0;
};
 
int main() {
  ThreadSafeCounter counter;
 
  auto increment_and_print = [&counter]() {
    for (int i = 0; i < 3; i++) {
      counter.increment();
      std::cout << std::this_thread::get_id() << ' ' << counter.get() << '\n';
 
      // Note: Writing to std::cout actually needs to be synchronized as well
      // by another std::mutex. This has been omitted to keep the example small.
    }
  };
 
  std::thread thread1(increment_and_print);
  std::thread thread2(increment_and_print);
 
  thread1.join();
  thread2.join();
}
/*
139677317637888 2
139677317637888 3
139677309245184 4
139677309245184 5
139677309245184 6
139677317637888 6
*/

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vdbzx5/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。