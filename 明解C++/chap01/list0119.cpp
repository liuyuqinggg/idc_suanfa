<<<<<<< HEAD:銆愭簮浠ｇ爜銆戞槑瑙++/chap01/list0119.cpp
// 读入姓名并打招呼（包括空格）
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string name;	// 姓名

	cout << "name:";		// 提示输入姓名
	getline(cin, name);			// 读入姓名（包括空格）

	cout << "hello " << name << ".\n";		// 打招呼
}
 
=======
// 读入姓名并打招呼（包括空格）

#include <string>
#include <iostream>

using namespace std;

int main()
{
	string name;	// 姓名

	cout << "姓名：";		// 提示输入姓名
	getline(cin, name);			// 读入姓名（包括空格）

	cout << "你好，" << name << "。\n";		// 打招呼
}
>>>>>>> b274cc34791ed0386873647df97f520c9ba42f8d:鏄庤ВC++/chap01/list0119.cpp
