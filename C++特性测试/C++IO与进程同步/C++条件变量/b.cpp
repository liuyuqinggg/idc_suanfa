// condition_variable::notify_one
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

std::mutex mtx;
std::condition_variable produce,consume;

int cargo = 0;     // shared value by producers and consumers

void consumer () {
std::unique_lock<std::mutex> lck(mtx);
while (cargo==0) consume.wait(lck);
std::cout << cargo << '\n';
cargo=0;
produce.notify_one();
}

void producer (int id) {
std::unique_lock<std::mutex> lck(mtx);
while (cargo!=0) produce.wait(lck);
cargo = id;
consume.notify_one();
}

int main ()
{
std::thread consumers[10],producers[10];
// spawn 10 consumers and 10 producers:
for (int i=0; i<10; ++i) {
    consumers[i] = std::thread(consumer);
    producers[i] = std::thread(producer,i+1);
}

// join them back:
for (int i=0; i<10; ++i) {
    producers[i].join();
    consumers[i].join();
}

return 0;
}

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vdftj2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。