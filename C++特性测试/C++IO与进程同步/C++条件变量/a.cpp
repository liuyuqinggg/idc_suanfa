#include <iostream>
#include <atomic>
#include <condition_variable>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;

std::condition_variable cv;
std::mutex cv_m;
int i;

void waits(int idx)
{
    std::unique_lock<std::mutex> lk(cv_m);
    if (cv.wait_for(lk, idx*100ms, []{return i == 1;})) {
        std::cerr << "Thread " << idx << " finished waiting. i == " << i << '\n';
    } else {
        std::cerr << "Thread " << idx << " timed out. i == " << i << '\n';
    }
}

void signals()
{
    std::this_thread::sleep_for(120ms);
    std::cerr << "Notifying...\n";
    cv.notify_all();
    std::this_thread::sleep_for(100ms);
    {
        std::lock_guard<std::mutex> lk(cv_m);
        i = 1;
    }
    std::cerr << "Notifying again...\n";
    cv.notify_all();
}

int main()
{
    std::thread t1(waits, 1), t2(waits, 2), t3(waits, 3), t4(signals);
    t1.join(); // t1 等待 100ms 后未被唤醒，自动超时；
    t2.join(); // t2 在 120 ms 处被唤醒，但 condition 未满足，再此进入阻塞，200ms 时由于超时返回
    t3.join(); // t3 在 120 ms 处被唤醒，但 condition 未满足，再此进入阻塞，220ms 时被 notify ，正常返回。
    t4.join();
}
/*
Thread 1 timed out. i == 0
Notifying...
Thread 2 timed out. i == 0
Notifying again...
Thread 3 timed out. i == 0
*/

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vdftj2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。