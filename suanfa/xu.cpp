#include "iostream"
#include "vector"
#include "string"
using namespace std;

//int sum = 0;
//int maxV = 0;
//
//vector<vector<int>> direct = {{1, 0}, {0, 1}};
//
//void backTracking(vector<string> &broad, vector<vector<int>> &prices, int x, int y, vector<vector<bool>> &used, int k) {
//    if (sum < 0) {
//        return;
//    }
//    if (sum > maxV) {
//        maxV = sum;
//    }
//    for (int i = 0; i < 2; ++i) {
//        int nextx = x + direct[i][0];
//        int nexty = y + direct[i][1];
//        if (nextx < 0 || nextx >= broad.size() || nexty < 0 || nexty >= broad[0].size()) continue;
////        if (used[nextx][nexty] == true) continue;
//        if (broad[x][y] == broad[nextx][nexty]) {
//            sum += prices[nextx][nexty];
////            used[nextx][nexty] = true;
//            backTracking(broad, prices, nextx, nexty, used, k);
////            used[nextx][nexty] = false;
//            sum -= prices[nextx][nexty];
//        }
//        if (broad[x][y] != broad[nextx][nexty]) {
//            if (sum - k < 0) {
//                continue;
//            }
//            sum = sum + prices[nextx][nexty] - k;
////            used[nextx][nexty] = true;
//            backTracking(broad, prices, nextx, nexty, used, k);
////            used[nextx][nexty] = false;
//            sum = sum - prices[nextx][nexty] + k;
//        }
//    }
//}

int retV = 0;
void dpFunc(vector<string> &broad, vector<vector<int>> &prices, vector<vector<int>> &dp, int k) {
    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 1; j < dp[0].size(); ++j) {
            dp[i][j] = -1;
            if (dp[i-1][j] != -1)  {
                if (broad[i-1][j] != broad[i][j]) {
                    if (dp[i-1][j] - k >= 0) {
                        dp[i][j] = max(dp[i][j], dp[i-1][j]+ prices[i][j] - k);
                    }
                } else if(broad[i-1][j] == broad[i][j]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j]+ prices[i][j]);
                }
            }
            if (dp[i][j-1] != -1) {
                if (broad[i][j-1] != broad[i][j]) {
                    if (dp[i][j-1] - k >= 0) {
                        dp[i][j] = max(dp[i][j], dp[i][j-1]+ prices[i][j] - k);
                    }
                } else if(broad[i][j-1] == broad[i][j]) {
                    dp[i][j] = max(dp[i][j], dp[i][j-1]+prices[i][j]);
                }
            }
            if (dp[i][j] > retV) {
                retV = dp[i][j];
            }
        }
    }
}

int main(){
    int n = 0, m = 0, k = 0;
    // cin >> n >> m >> k;
//    vector<vector<char>> broad(n, vector<char>(m));
//    for (int i = 0; i < n; ++i) {
//        string s;
//        cin >> s;
//        for (int j = 0; j < s.size(); ++j) {
//            broad[i][j] = s[j];
//        }
//    }
    vector<string> broad;
    // for (int i = 0; i < n; ++i) {
    //     string s;
    //     cin >> s;
    //     broad.push_back(s);
    // }
    vector<vector<int>> prices(n, vector<int>(m, -1));
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         int tmp = 0;
    //         cin >> tmp;
    //         prices[i][j] = tmp;
    //     }
    // }

    n = 5,m = 1, k = 6;

     prices = {{0},{2},{3},{6},{2}};
    
     broad = {"R","R","R","B","B"};


    

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 1; i < m; ++i) {
        if (broad[0][i] != broad[0][i-1]) {
            if (dp[0][i-1] - k < 0) {
                dp[0][i] = -1;
            }else if (dp[0][i-1] == -1) {
                dp[0][i] = -1;
            } else {
                dp[0][i] = dp[0][i-1] + prices[0][i] - k;
            }
        } else {
            dp[0][i] = dp[0][i-1] + prices[0][i];
        }
        if (dp[0][i] > retV) {
            retV = dp[0][i];
        }
    }

    for (int i = 1; i < n; ++i) {
        if (broad[i][0] != broad[i-1][0]) {
            if (dp[i-1][0] -k < 0) {
                dp[i][0] = -1;
            } else if (dp[i-1][0] == -1) {
                dp[i][0] = -1;
            } else {
                dp[i][0] = dp[i-1][0] + prices[i][0] - k;
            }
        } else {
            dp[i][0] = dp[i-1][0] + prices[i][0];
        }
        if (dp[i][0] > retV) {
            retV = dp[i][0];
        }
    }
    dpFunc(broad, prices, dp, k);
    cout << retV << endl;
    return 0;
}