#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    int helper(int i , int j ,string& s1, string& s2,int n,int m
                , vector<vector<int>>& dp)
    
    {
        if (i>=n|| j>=m) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        
        if (s1[i]==s2[j]){
            return dp[i][j]=1+helper(i+1,j+1,s1,s2,n,m,dp);
        }
        else 
        return dp[i][j]=0;
    }
    int longCommSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.size();
        int m=s2.size();
        
        // int ans = 0;

        // // try all starting points
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         vector<vector<int>>dp(n,vector<int>(m,-1));
        //         ans = max(ans, helper(i, j, s1, s2, n, m,dp));
        //     }
        // }

        // return ans;
        
        
        
        // tabulation 
        int ans=0;
        int ind=-1;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if (s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=0;
                
               if (dp[i][j]>ans){
                   ans=dp[i][j];
                   ind=i-1;
               }
            }
        }
        
        
    //   string str = "";

    //     if (ind != -1) {
    //         str = s1.substr(ind - ans + 1, ans);
    //     }
        
    //     cout << str << endl;
    
        return ans;
        
    }
};