//--- ��Ա�ࣨͷ�ļ���---//

#include <string>

class Member {
	std::string full_name;	// ����
	int			no;			// ��Ա���
	int			rank;		// ��Ա�ȼ�

public:
	// ���캯����������
	Member(std::string name, int number, int grade);

	// ��ȡ�ȼ�����ȡ����
	int get_rank() { return rank; }

	// ���õȼ�����������
	void set_rank(int grade) { rank = grade; }

	// ��ʾ��������
	void print();
};
