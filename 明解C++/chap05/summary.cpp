#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
	const int A_SIZE = 5;		// ����a��Ԫ�ظ���

	// ����a��bΪһά���飨Ԫ������Ϊint��Ԫ�ظ���Ϊ5��
	int a[A_SIZE];
	int b[] = {1, 2, 3, 4, 5};

	// ����b��Ԫ�ظ���
	int b_size = sizeof(b) / sizeof(b[0]);

	// ������b������Ԫ�ظ��Ƶ�a
	for (int i = 0; i < A_SIZE; i++)
		a[i] = b[i];

	// ��ʾ����a������Ԫ�ص�ֵ
	for (int i = 0; i < A_SIZE; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';

	// ��ʾ����b������Ԫ�ص�ֵ
	for (int i = 0; i < b_size; i++)
		cout << "b[" << i << "] = " << b[i] << '\n';

	// ���㲢��ʾ����a������Ԫ�صĺ�sum
	int sum = 0;
	for (int i = 0; i < A_SIZE; i++)
		sum += a[i];
	cout << "����a������Ԫ�صĺ�=" << sum << '\n'; 

	// ����cΪ��ά���飨Ԫ������Ϊint[3]����Ԫ�ظ���Ϊ2��
	int c[2][3] = { {1, 2, 3},
					{4, 5, 6},
				  };

	int c_height = sizeof(c) / sizeof(c[0]);		// ����
	int c_width  = sizeof(c[0]) / sizeof(c[0][0]);	// ����

	cout << "����cΪ" << c_height << "��" << c_width << "�е�"
		 << "��ά���顣\n";

	// ��ʾ����c����������Ԫ�ص�ֵ
	for (int i = 0; i < c_height; i++) {
		for (int j = 0; j < c_width; j++) {
			cout << "c[" << i << "][" << j << "] = " << c[i][j] << '\n';
		}
	}

	// ��ʾ���顢Ԫ�غ͹���Ԫ�ص�����
	cout << "����a�����ͣ�" << typeid(a).name()    << '\n';
	cout << "a��Ԫ�����ͣ�" << typeid(a[0]).name() << '\n';
	cout << "����b�����ͣ�" << typeid(b).name()    << '\n';
	cout << "b��Ԫ�����ͣ�" << typeid(b[0]).name() << '\n';
	cout << "����c�����ͣ�" << typeid(c).name()    << '\n';
	cout << "c��Ԫ�����ͣ�" << typeid(c[0]).name() << '\n';
	cout << "c�Ĺ���Ԫ�����ͣ�" << typeid(c[0][0]).name() << '\n';
}
