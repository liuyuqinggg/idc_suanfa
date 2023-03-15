#include<bits/stdc++.h>
using namespace std;

int t, k, n;
int a[10100];
unordered_map<int, int> mp;

int main () {
    cin >> t;
    while(t--) {
        mp.clear();
        cin >> n >> k;
        set<int> st;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            st.insert(a[i]);
            mp[a[i]]++;            
        }
        vector<int> v;
        sort(a, a + n);
        n = st.size();
        for(int i = 0; i < n; ++i) {
            a[i] = *st.begin();   
            st.erase(a[i]);
        }
        for(int i = 0; i < n; ++i) {
            v.push_back(mp[a[i]]);
        }
        int flag = false, sum = 0;
        int l = 0, r = 0;
        while(r < v.size()) {
            sum += v[r];
            if(sum > k) {
                sum -= v[l];
                l++;
                if(l > r) {
                    r = l;
				}
            } else if(sum < k) {
                r++;
            } else {
                cout << a[l] << ' ' << a[r] << endl;
                flag = true;
                break;
            }
        }
        if(!flag) {
            if(sum == k)
                cout << a[l] << ' ' << a[r] << endl;
            else
                puts("-1");
        }
    }
    
    return 0;
}