#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main(int argc, char const *argv[])
{
    int m = 3, n = 2, k = 2;

    vector<vector<int>> value = {{2,5},{4,3},{1,3}};
    vector<vector<int>> dp(m,vector<int>(3,0));
    vector<string> color = {"RR","BR","BB"};

    dp[0][0] = value[0][0];

    for(int i = 1; i < n; i++){
        if(color[0][i] == color[0][i - 1]){
            dp[0][i] = dp[0][i-1] + value[0][i];
        }else{
            dp[0][i] = dp[0][i-1] + value[0][i] - k;
        }
    }

    for(int i = 1; i < m; i++){
        if(color[i][0] == color[i - 1][0]){
            dp[i][0] = dp[i - 1][0] + value[i][0];
        }else{
            dp[i][0] = dp[i - 1][0] + value[i][0] - k;
        }
    }

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            int temp1,temp2;
            if(color[i][j] == color[i][j - 1]){
                temp1 = dp[i][j - 1]  + value[i][j];
            }else if(color[i][j] != color[i][j - 1]){
                temp1 = dp[i][j - 1]  + value[i][j] - k;
            }

            if(color[i][j] == color[i - 1][j]){
                temp2 = dp[i - 1][j]  + value[i][j];
            }else if(color[i][j] != color[i - 1][i]){
                temp2 = dp[i - 1][j]  + value[i][j] - k;
            }

            dp[i][j] = max(temp1,temp2);
        }
    }

    cout << dp[m - 1][n - 1];




    return 0;
}
