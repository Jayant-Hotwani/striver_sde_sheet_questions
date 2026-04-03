#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int dp[102][102];
    // int helper(int i , int j , vector<int>& cuts){
    //     if (i>j) return 0;
    //     if (dp[i][j]!=-1) return dp[i][j];
    //     int min_cuts=1e9;
    //     for(int k=i;k<=j;k++){
    //         int temp=cuts[j+1]-cuts[i-1];
    //         min_cuts=min(min_cuts,temp+helper(i,k-1,cuts)+helper(k+1,j,cuts));
    //     }

    //     return dp[i][j]=min_cuts;
    // }
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        // memset(dp,-1,sizeof(dp));
        n=cuts.size();
        // return helper(1,n-2,cuts);

        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=n-2;i>=1;i--){
            for(int j=i;j<=n-2;j++){
                int mini = 1e9;

                for(int k = i; k <= j; k++){
                    int cost = cuts[j+1] - cuts[i-1]
                             + dp[i][k-1]
                             + dp[k+1][j];

                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }
        return dp[1][n-2];
    }
};