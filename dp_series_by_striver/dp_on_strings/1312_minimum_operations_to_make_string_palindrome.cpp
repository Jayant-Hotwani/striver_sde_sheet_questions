#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcs( int index1 , int index2 ,string& s , string& t , int n,
    vector<vector<int>>& dp )
    {
        if (index1>=n || index2>=n) return 0;
        
        if (dp[index1][index2]!=-1) return dp[index1][index2];
        if(s[index1]==t[index2]){
            return dp[index1][index2]=1+lcs(index1+1,index2+1,s,t,n,dp);
        }
        else 
        return dp[index1][index2]=max(
            lcs(index1,index2+1,s,t,n,dp),
            lcs(index1+1,index2,s,t,n,dp));
    }
    int lps (string& s){
        string t=s;
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        reverse(t.begin(),t.end());
        return lcs(0,0,s,t,n,dp);
    }
    int minInsertions(string s) {
        int n=s.size();

        return n-lps(s);
    }
};