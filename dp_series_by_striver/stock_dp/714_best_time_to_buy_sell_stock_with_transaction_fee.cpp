#include <bits/stdc++.h>
using namespace std;
class Solution {
public: 
    // int dp[50001][3];
    // int helper(int index , vector<int>& prices , bool canBuy , int fee){
    //     if (index>=prices.size())return 0;

    //     if (dp[index][canBuy]!=-1) return dp[index][canBuy];
    //     int profit=0;
    //     if(canBuy){
    //         // buy
    //         profit=max(profit,-1*prices[index] + helper(index+1,prices,!canBuy,fee));
    //         // not buy
    //         profit=max(profit,helper(index+1,prices,canBuy,fee));
    //     }
    //     else{
    //         // sell 
    //         profit=max(profit,prices[index] - fee + helper(index+1,prices,!canBuy,fee));
    //         // notsell
    //         profit=max(profit,helper(index+1,prices,canBuy,fee));

    //     }

    //     return dp[index][canBuy]=profit;
    // }
    int maxProfit(vector<int>& prices, int fee) {
        // memset(dp,-1,sizeof(dp));
        // return helper(0,prices,true,fee);

        // int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,0));

        // dp[n][1]=0;
        // dp[n][0]=0;
        // for(int index=n-1;index>=0;index--){
        //     for(int canBuy=0;canBuy<2;canBuy++){
        //         int profit=0;
        //         if(canBuy){
        //             // buy
        //             profit=max(profit,-1*prices[index] + dp[index+1][!canBuy]);
        //             // not buy
        //             profit=max(profit,dp[index+1][canBuy]);
        //         }
        //         else{
        //             // sell 
        //             profit=max(profit,prices[index] - fee + dp[index+1][!canBuy]);
        //             // notsell
        //             profit=max(profit,dp[index+1][canBuy]);

        //         }
        //         dp[index][canBuy]=profit;
        //     }
        // }
        // return dp[0][1];


        // space_optimised


         int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,0));

        // vector<int>ahead(2,0);
        // vector<int>curr(2,0);

        // ahead[1]=0;
        // ahead[0]=0;
        // for(int index=n-1;index>=0;index--){
        //     for(int canBuy=0;canBuy<2;canBuy++){
        //         int profit=0;
        //         if(canBuy){
        //             // buy
        //             profit=max(profit,-1*prices[index] + ahead[!canBuy]);
        //             // not buy
        //             profit=max(profit,ahead[canBuy]);
        //         }
        //         else{
        //             // sell 
        //             profit=max(profit,prices[index] - fee + ahead[!canBuy]);
        //             // notsell
        //             profit=max(profit,ahead[canBuy]);

        //         }
        //         curr[canBuy]=profit;
        //     }
        //     ahead=curr;
        // }
        // return ahead[1];

        // more optimised 
        int ahead_buy,ahead_sell,curr_buy,curr_sell;
        // vector<int>ahead(2,0);
        // vector<int>curr(2,0);

        ahead_buy=0;
        ahead_sell=0;
        for(int index=n-1;index>=0;index--){
            for(int canBuy=0;canBuy<2;canBuy++){
                int profit=0;
                if(canBuy){
                    // buy
                    profit=max(profit,-1*prices[index] + ahead_sell);
                    // not buy
                    profit=max(profit,ahead_buy);
                }
                else{
                    // sell 
                    profit=max(profit,prices[index] - fee + ahead_buy);
                    // notsell
                    profit=max(profit,ahead_sell);

                }
                if (canBuy)
                curr_buy=profit;
                else
                curr_sell=profit;
            }
            ahead_buy=curr_buy;
            ahead_sell=curr_sell;
            // ahead=curr;
        }
        return ahead_buy;

    }
};