// ������Date����1�棺ͷ�ļ���

class Date {
	int y;		// ������
	int m;		// ��
	int d;		// ��

public:
	Date(int yy, int mm, int dd);	// ���캯��
	int year()  { return y; }		// ������
	int month() { return m; }		// ������
	int day()   { return d; }		// ������
};
