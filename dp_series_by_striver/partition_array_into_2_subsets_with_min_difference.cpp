#include <bits/stdc++.h>
using namespace std;
class Solution {

  public:
    int minDifference(vector<int>& nums) {
        // Your code goes here
        
        int total_sum=0;
        for(int i=0;i<nums.size();i++){
            total_sum+=nums[i];
        }
        
        int target=total_sum/2;
        int n=nums.size();
        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        
        for(int i=0;i<n;i++)
        dp[i][0]=true;
        
        if (nums[0]<=target)dp[0][nums[0]]=true;
        
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool np=dp[i-1][j];
                bool p=false;
                if (j>=nums[i]){
                    p=dp[i-1][j-nums[i]];
                }
                dp[i][j] = p || np;   
            }
        }
        
        int ans=1e9;
        for(int j=0;j<=target;j++){
            if (dp[n-1][j]){
                ans=min(ans,abs(total_sum-(2*j)));
            }
        }
        return ans;
    }
};
