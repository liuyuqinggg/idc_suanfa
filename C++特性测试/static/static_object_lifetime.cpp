#include<iostream>
using namespace std;

class GfG1
{
	int i;
	public:
		GfG1()
		{
			i = 0;
			cout << "GFG1 Inside Constructor\n";
		}
		~GfG1()
		{
			cout << "GFG1 Inside Destructor\n";
		}
};

class GfG2
{
	int i;
	public:
		GfG2()
		{
			i = 0;
			cout << "GfG2 Inside Constructor\n";
		}
		~GfG2()
		{
			cout << "GfG2 Inside Destructor\n";
		}
};

int main()
{
	int x = 0;
	if (x==0)
	{
		GfG1 obj1;
        static GfG2 obj2; //进程结束才会调用析构函数
	}
	cout << "End of main\n";
}

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vwrt6c/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。