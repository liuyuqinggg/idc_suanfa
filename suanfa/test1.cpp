#include<iostream>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    // cin >> s;

    s = "100000";

    int res = 0;

    if(s.length() == 1) return 0;
    if(s.length() == 2 ){
        if(s[0] != s[1]){
             return 0;
        }else{
            return 1;
        }
    }

    for (int i = 0; i < s.length(); i++)
    {
        if(i + 1 < s.length()){
            if(s[i] == s[i + 1]){
                res++;
                i++;
            }
        }
        
    }
    
    cout << res;
    return 0;
}
