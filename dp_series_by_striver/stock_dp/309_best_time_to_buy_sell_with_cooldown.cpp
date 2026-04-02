#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int helper(int index,vector<int>& prices,int n,bool buy,vector<vector<int>>&dp)
    {
        if (index>=n) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        int profit=0;
        if (buy){
            int did_buy=-1*prices[index]+helper(index+1,prices,n,!buy,dp);
            int did_not_buy=helper(index+1,prices,n,buy,dp);
            profit=max(did_buy,did_not_buy);
        }
        else{
            int did_sell=1*prices[index]+helper(index+2,prices,n,!buy,dp);
            int did_not_sell=helper(index+1,prices,n,buy,dp);
            profit=max(did_sell,did_not_sell);
        }

        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {

        int n =prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return helper(0,prices,n,true,dp);

        // tabulation

        vector<vector<int>>dp(n+2,vector<int>(2,0));

        dp[n][0]=0;
        dp[n][1]=0;
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<2;buy++){
                int profit=0;
                if (buy){
                    int did_buy=-1*prices[index]+dp[index+1][!buy];
                    int did_not_buy=dp[index+1][buy];
                    profit=max(did_buy,did_not_buy);
                }
                else{
                    int did_sell=1*prices[index]+dp[index+2][!buy];
                    int did_not_sell=dp[index+1][buy];
                    profit=max(did_sell,did_not_sell);
                }

                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    }
};