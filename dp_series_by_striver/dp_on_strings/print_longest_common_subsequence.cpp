#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int helper(int i , int j ,string& text1, string& text2, int n , int m,
    //            vector<vector<int>>& dp)
    // {
    //     if(i>=n || j>=m) return 0;

    //     if (dp[i][j]!=-1)
    //     return dp[i][j];

    //     if (text1[i]==text2[j]){
    //         return dp[i][j]=1+helper(i+1,j+1,text1,text2,n,m,dp);
    //     }
    //     return dp[i][j]=max(helper(i,j+1,text1,text2,n,m,dp),
    //                         helper(i+1,j,text1,text2,n,m,dp));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.size();
        int m=text2.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return helper(0,0,text1,text2,n,m,dp);



        // tabulation 

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if (text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        


        // space optimised 

        // vector<int>curr(m+1,0);
        // vector<int>prev(m+1,0);
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if (text1[i-1]==text2[j-1]){
        //             curr[j]=1+prev[j-1];
        //         }
        //         else{
        //             curr[j]=max(prev[j],curr[j-1]);
        //         }
        //     }
        //     prev=curr;
        // }

        // return prev[m];




        // finding out actual string 

        string ans="";
        int i=n,j=m;
        while(i>0 && j>0){
            if (text1[i-1]==text2[j-1]){
                ans+=text1[i-1];
                i--;j--;
            }
            else{
                if (dp[i-1][j]>dp[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }

        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;

        return dp[n][m];

    }
};