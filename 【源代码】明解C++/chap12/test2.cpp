// ��ʼ���͸�ֵ��ֵ���ݺ����ô��ݵ���֤
// ����֤ΪĿ�ģ�ֵ���ݸ�ֵ������Ĳ���

#include <iostream>

using namespace std;

//===== ������֤���� =====//
class Test {
public:
	Test() {							// Ĭ�Ϲ��캯��
		 cout << "��ʼ����Test()\n";
	}

	Test(const Test& t) {				// ���ƹ��캯��
		cout << "��ʼ����Test(const Test&)\n";
	}

	Test& operator=(Test t) {			// ��ֵ�����
		cout << "��ֵ��Test = Test\n";  return *this;
	}
};

//--- ֵ���� ---//
void value(Test a) { }

//--- ���ô��� ---//
void reference(Test& a)  { }

int main()
{
	Test x;		  // Ĭ�Ϲ��캯��
	Test y = x;	  // ���ƹ��캯��
	Test z(x);	  // ���ƹ��캯��
	y = x;		  // ��ֵ�����
	value(x);	  // �������ã�ֵ���ݣ�
	reference(x); // �������ã����ô��ݣ�
}
