// string���ʹ������

#include <string>
#include <iostream>

using namespace std;

int main()
{
	string s1 = "ABC";
	string s2 = "HIJKLMN";
	string digits = "0123456789";

	s1 += "DEF";							// ��s1��ĩβƴ��"DEF"
	s1 += 'G';								// ��s1��ĩβƴ��'G'
	s1 += s2;								// ��s1��ĩβƴ��"HIJKLMN"
	s1.insert(6, digits.substr(5, 3));		// ��s1[6]����"567"

	s2.replace(3, 2, "kl");					// ��s2[3]~s2[4]�滻Ϊ"kl"
	s2.erase(6);							// ɾ��s2[6]

	cout << "s1 = ";
	for (int i = 0; i < s1.length(); i++)
		cout << s1[i];
	cout << '\n';
	cout << "s2 = " << s2 << '\n';
}
