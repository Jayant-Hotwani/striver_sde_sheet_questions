#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int index, int prev , vector<int>& nums , int n, vector<vector<int>>& dp){
        if (index>=n) return 0;
        if (dp[index][prev+1]!=-1) return dp[index][prev+1];

        int ans=0;
        if (prev==-1 || nums[index]>nums[prev]){
            ans=max(ans,1+helper(index+1,index,nums,n,dp));
        }
        ans=max(ans,helper(index+1,prev,nums,n,dp));

        return dp[index][prev+1]= ans;
    }
    int lengthOfLIS(vector<int>& nums) {

        int n =nums.size();

        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return helper(0,-1,nums,n,dp);

        // tabulation 
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        // for(int index=n-1;index>=0;index--){
        //     for(int prev=n-1;prev>=-1;prev--){
        //         int ans=0;
        //         if (prev==-1 || nums[index]>nums[prev]){
        //             ans=max(ans,1+dp[index+1][index+1]);
        //         }
        //         ans=max(ans,dp[index+1][prev+1]);       
        //         dp[index][prev+1]= ans;
        //     }
        // }
        // return dp[0][0];

        // more optimised

        

        // vector<int>dp(n,1);
        // int ans=1;
        // for(int i=0;i<n;i++){
        //     for(int prev=0;prev<i;prev++){
        //         if (nums[i]>nums[prev]){
        //             dp[i]=max(dp[i],1+dp[prev]);
        //             ans=max(ans,dp[i]);
        //         }
        //     }
        // }

        // return ans;

        // how to print lis

        // int ans_index=0;
        // vector<int>dp(n,1);
        // vector<int>parent(n);
        // for(int i=0;i<n;i++)parent[i]=i;

        // int ans=1;
        // for(int i=0;i<n;i++){
        //     for(int prev=0;prev<i;prev++){
        //         if (nums[i]>nums[prev]){
        //             if (dp[i]<1+dp[prev]){
        //                 ans_index=i;
        //                 dp[i]=1+dp[prev];
        //                 parent[i]=prev;
        //             }
        //             ans=max(ans,dp[i]);
        //         }
        //     }
        // }

        // vector<int>print;
        // int start=ans_index;
        // while(parent[start]!=start){
        //     print.push_back(nums[start]);
        //     start=parent[start];
        // }
        // print.push_back(nums[start]);
        // reverse(print.begin(),print.end());
        // for(auto x:print)
        // cout<<x<< " ";

        // cout<<endl;

        // return ans;


        // how to improve time complexity 
        // use binary search for that 

        // in this case , we dont store subseq , we are concerned over length only 
        // we cannot re gernate

        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back())
            temp.push_back(nums[i]);
            else{
                int index=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[index]=nums[i];
            }
        }

        return temp.size();



        
    }
};