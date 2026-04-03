//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int mod=1003;
typedef long long int lli;
class Solution{
public:
   
    int helper (int i , int j , int istrue, string &s ,vector<vector<vector<lli>>> &dp )
    {
        if (i>j) return 0;
        if (i==j)
        {
            if (istrue) return s[i]=='T';
            else
            return s[i]=='F';
        }
        
        if (dp[i][j][istrue]!=-1)
        return dp[i][j][istrue];
        
        lli ways=0;
        for (int index=i+1;index<=j-1;index++)
        {
            lli lt=helper (i,index-1,1,s,dp);
            lli rt=helper (index+1,j,1,s,dp);
            lli lf=helper (i,index-1,0,s,dp);
            lli rf=helper (index+1,j,0,s,dp);
            
            if (s[index]=='&')
            {
                if (istrue)
                ways=(ways+(lt*rt)%mod)%mod;
                else
                ways=(ways+(lt*rf)+(lf*rt)+(lf*rf))%mod;
                
            }
            else if (s[index]=='|')
            {
                if (istrue)
                ways=(ways+(rt*lt)+(rt*lf)+(lt*rf))%mod;
                else
                {
                    ways=(ways+(lf*rf))%mod;
                }
            }
            else
            {
                if (istrue)
                {
                    ways=(ways+(rf*lt)+(rt*lf))%mod;
                    
                }
                else
                {
                    ways=(ways+(rt*lt)+(rf*lf))%mod;
                }
            }

        }
        
        return dp[i][j][istrue]=ways%mod;
        
    }

    int countWays(int N, string S){
        // code here
        vector<vector<vector<lli>>>dp(N,vector<vector<lli>>(N,vector<lli>(2,-1)));
        return helper(0,N-1,1,S,dp); 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends