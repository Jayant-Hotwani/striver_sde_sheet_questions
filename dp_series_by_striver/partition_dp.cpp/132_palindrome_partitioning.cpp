#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool ispalindrome(int start , int end , string& s){
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }

        return true;
    }

    int helper(int index , string& s , int n , vector<int>& dp){
        if (index>=n)return 0;
        if(dp[index]!=-1) return dp[index];

        int ans=1e9;
        string str="";
        for(int k=index;k<n;k++){
            str+=s[k];
            if (ispalindrome(0,str.size()-1,str)){
                ans=min(ans,1+helper(k+1,s,n,dp));
            }
        }

        return dp[index]= ans;
    }
    int minCut(string s) {
        int n=s.size();
        if (ispalindrome(0,n-1,s))return 0;
        // vector<int>dp(n,-1);
        // return helper(0,s,n,dp)-1;


        vector<int>dp(n+1,0);
        dp[n]=0;
        for(int index=n-1;index>=0;index--){
            int ans=1e9;
            string str="";
            for(int k=index;k<n;k++){
                str+=s[k];
                if (ispalindrome(0,str.size()-1,str)){
                    ans=min(ans,1+dp[k+1]);
                }
            }
            dp[index]= ans;
        }
        return dp[0]-1;
    }
};