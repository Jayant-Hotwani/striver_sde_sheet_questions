#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),ways(n,1);
        int maxi=1;
        for(int index =0; index<n ; index++){
            for(int prev=0;prev<index;prev++){
                if (nums[index]>nums[prev]){
                    if (dp[index]<1+dp[prev]){
                        dp[index]=1+dp[prev];
                        ways[index]=ways[prev];
                    }
                    else if(dp[index]==1+dp[prev]){
                        ways[index]+=ways[prev];
                    }
                }
            }
            maxi=max(maxi,dp[index]);
        }

        int ans=0;
        for(int index=0;index<n;index++){
            if (dp[index]==maxi){
                ans+=ways[index];
            }
        }
        return ans;
    }
};