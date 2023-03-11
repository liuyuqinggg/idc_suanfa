#include<iostream>
#include<vector>

using namespace std;

class Solution
{
private:
    /* data */
public:
    int maxHappy(vector<int> &cost,vector<int> &value, int totle){
        //每个商品有三个状态 0：原价拿了，1：半价拿了 2：没拿

        //dp[i][j][0],表示总共有j元，在前0...i的商品中能够拿到的最大价值，并且第i件商品是原价拿的
        //dp[i][j][1],表示总共有j元，在前0...i的商品中能够拿到的最大价值，并且第i件商品是半价拿的
        //dp[i][j][2],表示总共有j元，在前0...i的商品中能够拿到的最大价值，并且第i件商品是没拿的

        vector< vector< vector<int> > > dp = vector(cost.size(),vector(totle,vector<int>(3,0)));

        for(int i = 0; i < cost.size(); i++){
            for(int j = 0; j < totle; j++){

                //第i件商品不拿
                dp[i][j][2] = max(dp[i-1][j][0],max(dp[i-1][j][1],dp[i-1][j][2]));

                //第i件商品以原价拿

                if(totle >= cost[i]){
                    dp[i][j][0] = max(dp[i][j - cost[i]][0],max(dp[i][j - cost[i]][1],dp[i][j - cost[i]][2])) + value[i];
                }
                if(totle >= cost[i] / 2 && totle < cost[i]){ //表示可以用半价拿  ，但是还要判断前一个商品是否是半价拿的，如果是则不可以半价拿
                    //如果前一个商品是全价拿的，或者没拿，则可以半价拿走
                    if(dp[i-1][j][0] == max(dp[i-1][j - cost[i-1]][0],max(dp[i-1][j - cost[i-1]][1],dp[i-1][j - cost[i-1]][2])) + value[i-1] \
                     || dp[i-1][j][2] == max(dp[i-2][j][0],max(dp[i-2][j][1],dp[i-2][j][2])) ){
                        dp[i][j][0] = max(dp[i][j - cost[i]][0],max(dp[i][j - cost[i]][1],dp[i][j - cost[i]][2])) + value[i];
                     }
                }
            }
        }



    }
};

