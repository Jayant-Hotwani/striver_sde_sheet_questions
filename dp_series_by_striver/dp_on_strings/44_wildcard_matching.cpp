#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool helper(int i , int j , string& s , string& p , int n ,int m ,
                vector<vector<int>>& dp){

        if (i==n){
            if(j==m)return true;
            else{
                for(int k=j;k<m;k++)if(p[k]!='*')return false;

                return true;
            }
        }
        if (j==m){
            if (i==n) return true;
            return false;
        }

        if (dp[i][j]!=-1)return dp[i][j];
    
        if (s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=helper(i+1,j+1,s,p,n,m,dp);
        }
        else if(p[j]=='*'){
            // match one -- // match none 
            return dp[i][j]=helper(i+1,j,s,p,n,m,dp)||helper(i,j+1,s,p,n,m,dp); 
        }

        return false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return helper(0,0,s,p,n,m,dp);


        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        //base case
        for(int j=1;j<=m;j++){
            if (p[j-1]=='*'){
                dp[0][j]=dp[0][j-1];
            }
        }


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if (s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                     dp[i][j]=dp[i][j-1]||dp[i-1][j];
                }
                else 
                dp[i][j]=false;
            }
        }

        return dp[n][m];
    }
};