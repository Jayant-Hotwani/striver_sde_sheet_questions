#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][3][101];

    int helper(int index,
               vector<int>& prices,
               int transactions,
               bool canBuy) {

        if (index == prices.size() || transactions == 0)
            return 0;

        if (dp[index][canBuy][transactions] != -1)
            return dp[index][canBuy][transactions];

        int profit = 0;

        if (canBuy) {
            profit = max(
                -prices[index] +
                helper(index+1, prices, transactions, false),
                helper(index+1, prices, transactions, true)
            );
        } else {
            profit = max(
                prices[index] +
                helper(index+1, prices, transactions-1, true),
                helper(index+1, prices, transactions, false)
            );
        }

        return dp[index][canBuy][transactions] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        // memset(dp, -1, sizeof(dp));
        // return helper(0, prices, k, true);
         int transactions=k;
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return helper(0,prices,n,true,transactions,dp);

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>
        (2,vector<int>(transactions+1,-1)));

        for(int i=0;i<=n;i++){
            for(int buy=0;buy<2;buy++){
                dp[i][buy][0]=0;
            }
        }
        for(int buy=0;buy<2;buy++){
            for(int trans=0;trans<k+1;trans++){
                dp[n][buy][trans]=0;
            }
        }

        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<2;buy++){
                for(int transactions=1;transactions<k+1;transactions++){
                    int profit=0;
                    if (buy){
                        int buyed=-1*prices[index]+dp[index+1][0][transactions];
                        int not_buyed=dp[index+1][1][transactions];
                        profit=max(buyed,not_buyed);
                    }
                    else{
                        int sold=1*prices[index]+dp[index+1][1][transactions-1];
                        int not_sold=dp[index+1][0][transactions];
                        profit=max(sold,not_sold);
                    }
                    dp[index][buy][transactions]=profit;
                }
            }
        }
        return dp[0][1][k];
    }
};