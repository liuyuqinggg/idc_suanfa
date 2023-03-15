#include<bits/stdc++.h>
using namespace std;

int t;
string s;

int main () {
    cin >> t;
    string tar = "Baidu";
    sort(tar.begin(), tar.end());
    while(t--) {
        cin >> s;
        sort(s.begin(), s.end());
        if(s == tar)
            puts("Yes");
        else
            puts("No");
    }
    
    return 0;
}