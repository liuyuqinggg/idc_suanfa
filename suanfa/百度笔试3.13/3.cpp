#include<bits/stdc++.h>
using namespace std;

int x;

int main () {
    cin >> x;
    string s = "", base = "red";
    int n = 1;
    while(n * (n - 1) / 2 + n <= x / 2) {
        n++;
    }
    n--;
    //  先填 n 个 r 和 n 个 e 
    int len = (n * (n - 1) / 2 + n) * 2;
    s += string(n, 'r') + string(n, 'e');
    if(len == x) {
        cout << s << endl; 
        return 0;
	}
	//  有剩下的，再填个 d 
    s += 'd';
    len += 1;
    //	还有剩，就填 red 循环 
    while(len + 3 < x) {
        s += base;
        len += 3;
    }
    if(len == x) {
        cout << s << endl;
	}
    else {
        s += base.substr(0, x - len);
        cout << s << endl;
    }

    cout << s.length() <<endl;
    
    return 0;
}