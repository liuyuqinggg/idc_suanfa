#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int getMax(vector<vector<int>>& v, int n)
{
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        int tmp = 1;
        int j = i + 1;
        int l = v[i][0];
        int r = v[i][1];
        while (j < n && v[j][0] <= r)
        {
            j++;
            tmp++;
        }
        res = max(res, tmp);
        tmp = 1;
    }
    return res;
}

int getMaxt(vector<vector<int>>& v, int n, int k)
{
    int res = 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp = 1;
        int j = i + 1;
        int l = v[i][0];
        int r = v[i][1];
        while (j < n && v[j][0] <= r)
        {
            j++;
            tmp++;
        }
        res = max(res, tmp);
        if (res == k)
        {
            ans += v[i][1] - v[j - 1][0] + 1;
            if (j == n)break;
        }
        tmp = 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int>s;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        s.push_back(tmp);
    }
    vector<int>t;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        t.push_back(tmp);
    }
    int maxcount = 0;
    int maxt = 0;
    vector<vector<int>>v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({ s[i], t[i] });
    }
    sort(v.begin(), v.end());
    maxcount = getMax(v, n);
    maxt = getMaxt(v, n, maxcount);
    cout << maxcount << " " << maxt << endl;

    return 0;
}