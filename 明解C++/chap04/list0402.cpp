// 判断简单字符型是有符号字符型还是无符号字符型

#include <climits>
#include <iostream>

using namespace std;

int main()
{
	cout << "该处理系统的简单字符型是"
		 <<	(CHAR_MIN ? "有符号" : "无符号") << "字符型。\n";
}
