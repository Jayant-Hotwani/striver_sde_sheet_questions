#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int i , int j ,string& word1, string& word2 , int n , int m,
               vector<vector<int>>& dp)
    {
        if (i==n) return m-j;
        if (j==m) return n-i;
        if (dp[i][j] != -1) return dp[i][j];
        if (word1[i]==word2[j]){
            return dp[i][j]=helper(i+1,j+1,word1,word2,n,m,dp);
        }
        return dp[i][j]=min({
            1+helper(i,j+1,word1,word2,n,m,dp),// insert
            1+helper(i+1,j,word1,word2,n,m,dp),//delete
            1+helper(i+1,j+1,word1,word2,n,m,dp)//replace
        });

    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return helper(0,0,word1,word2,n,m,dp);

        // tabulation 
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=i;
        for(int j=0;j<=m;j++)dp[0][j]=j;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min({
                        1+dp[i][j-1],//insert
                        1+dp[i-1][j],//delete
                        1+dp[i-1][j-1]//replace
                    });
                }
            }
        }

        return dp[n][m];

    }
};