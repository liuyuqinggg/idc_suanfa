#include <iostream>
#include <thread>
#include <chrono>
#include <semaphore>
 
std::binary_semaphore
	smphSignalMainToThread{0},
	smphSignalThreadToMain{0};
 
void ThreadProc()
{	
    // 第一次进入阻塞
	smphSignalMainToThread.acquire();
	std::cout << "[thread] Got the signal\n"; // response message
	using namespace std::literals;
	std::this_thread::sleep_for(3s);
	std::cout << "[thread] Send the signal\n"; // message
    // 唤醒 main 线程
	smphSignalThreadToMain.release();
}
 
int main()
{
	std::thread thrWorker(ThreadProc);
	std::cout << "[main] Send the signal\n"; // message
    // 唤醒 ThreadProc 
	smphSignalMainToThread.release();
    // main 线程阻塞
	smphSignalThreadToMain.acquire();
	std::cout << "[main] Got the signal\n"; // response message
	thrWorker.join();
}
/*
[main] Send the signal
[thread] Got the signal
[thread] Send the signal
[main] Got the signal
*/

// ; 作者：力扣 (LeetCode)
// ; 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vdbzx5/
// ; 来源：力扣（LeetCode）
// ; 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。