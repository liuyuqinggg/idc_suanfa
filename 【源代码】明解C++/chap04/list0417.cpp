// ��ʾ��ѡ����Ľ���

#include <iostream>

using namespace std;

int main()
{
	enum animal { Dog, Cat, Monkey, Invalid };
	int type;

	do {
		cout << "0...�� 1...è 2...�� 3...������";
		cin >> type;
	} while (type < Dog || type > Invalid);

	if (type != Invalid) {
		animal selected = static_cast<animal>(type);
		switch (selected) {
		 case Dog	 : cout << "����!!\n";	break;
		 case Cat	 : cout << "����!!\n";	break;
		 case Monkey : cout << "����!!\n";	break;
		}
	}
}
