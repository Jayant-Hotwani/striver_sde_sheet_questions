#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int index ,vector<int>& arr,int n,int k,vector<int>& dp){
        if (index>=n) return 0;
        if (dp[index]!=-1) return dp[index];
        int sum=0;
        int maxi=-1e9;
        for(int partition=index;partition<min(n,index+k);partition++){
            int len=(partition-index+1);
            maxi=max(maxi,arr[partition]);
            int part_sum=(len*maxi);
            sum=max(sum,part_sum+helper(partition+1,arr,n,k,dp));
        }

        return dp[index]=sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n =arr.size();
        // vector<int>dp(n,-1);
        // return helper(0,arr,n,k,dp);

        vector<int>dp(n+1,0);
        for(int index=n-1;index>=0;index--){
            int sum=0;
            int maxi=-1e9;
            for(int partition=index;partition<min(n,index+k);partition++){
                int len=(partition-index+1);
                maxi=max(maxi,arr[partition]);
                int part_sum=(len*maxi);
                sum=max(sum,part_sum+dp[partition+1]);
            }
            dp[index]=sum;
        }

        return dp[0];
    }
};