#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {


        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>parent(n);
        for(int i=0;i<n;i++) parent[i]=i;

        vector<int>dp(n,1);
        int ans_index=0;
        int maxi_len=0;
        for(int index=0;index<n;index++){
            for(int prev=0;prev<index;prev++){
                if (nums[index]%nums[prev]==0){
                    if (dp[index]<1+dp[prev]){
                        dp[index]=1+dp[prev]; 
                        parent[index]=prev;
                    }
                    if (dp[index]>maxi_len){
                        maxi_len=dp[index];
                        ans_index=index;
                    }
                }
            }
        }
        vector<int>ans;
        while(parent[ans_index]!=ans_index){
            ans.push_back(nums[ans_index]);
            ans_index=parent[ans_index];
        }
        ans.push_back(nums[ans_index]);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};