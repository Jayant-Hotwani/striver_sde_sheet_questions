#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[301][301];
    int helper(int start , int end ,vector<int>& nums){
        if(start>end) return 0;
        if (dp[start][end]!=-1) return dp[start][end];

        int coins=0;
        for(int index=start;index<=end;index++){
            int temp=nums[start-1]*nums[index]*nums[end+1];
            coins=max(coins,temp+helper(start,index-1,nums)+helper(index+1,end,nums));
        }
        return dp[start][end]=coins;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size();
        // memset(dp,-1,sizeof(dp));
        // return helper(1,n-2,nums);


        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int start=n-2;start>=1;start--){
            for(int end=0;end<=n-2;end++){
                if (start>end) continue;
                int coins=0;
                for(int index=start;index<=end;index++){
                    int temp=nums[start-1]*nums[index]*nums[end+1];
                    coins=max(coins,
                    temp+dp[start][index-1]+dp[index+1][end]);
                }
                dp[start][end]=coins;
            }
        }
        return dp[1][n-2];
        
    }
};