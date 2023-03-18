#include <iostream>
using namespace std;
#include <memory>

class Rectangle {
	int length;
	int breadth;

public:
	Rectangle(int l, int b){
		length = l;
		breadth = b;
	}

	int area(){
		return length * breadth;
	}
};

int main(){
	unique_ptr<Rectangle> P1(new Rectangle(10, 5));
	cout << P1->area() << endl; // This'll print 50

	unique_ptr<Rectangle> P2;
	// unique_ptr<Rectangle> P2(P1); // 无法拷贝构造
	// P2 = P1;   // 无法赋值构造
	P2 = move(P1);

	cout << P2->area() << endl;
	
	// cout<<P1->area()<<endl; // 已经传递，P1 无所有权
	return 0;
}

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/vv16rj/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。