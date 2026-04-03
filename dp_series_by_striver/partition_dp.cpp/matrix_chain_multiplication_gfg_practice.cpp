#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int dp[101][101];
    int helper(int i, int j , vector<int>& arr){
        if (i==j) return 0;
        if (dp[i][j]!=-1)
        return dp[i][j];
        
        int steps=1e9;
        for(int k=i;k<j;k++){
            int cost=arr[i-1]*arr[k]*arr[j];
            steps=min(steps,(cost)+helper(i,k,arr)+helper(k+1,j,arr));
        }
        return dp[i][j]=steps;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n =arr.size();
        // memset(dp,-1,sizeof(dp));
        // return helper(1,n-1,arr);
        
        
        // tabulation
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
            
            int steps=1e9;
                for(int k=i;k<j;k++){
                    int cost=arr[i-1]*arr[k]*arr[j];
                    steps=min(steps,(cost)+dp[i][k]+dp[k+1][j]);
                }
             dp[i][j]=steps;    
            }
        }
        
        return dp[1][n-1];
    }
};