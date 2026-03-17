#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int i , int j , vector<vector<char>>& board,vector<vector<bool>>& vis){
        if (i<0 || j<0 || i>=board.size() || j>=board[0].size() 
        || board[i][j]=='X' || vis[i][j]==true ) {
            return ;
        }
        vis[i][j]=true;
        dfs(i+1,j,board,vis);
        dfs(i,j+1,board,vis);
        dfs(i,j-1,board,vis);
        dfs(i-1,j,board,vis);
    }

    void solve(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if (i==0 || j==0 || i==n-1 || j==m-1){
                    if (vis[i][j]==false){
                        dfs(i,j,board,vis);
                    }
                }
            }
        }

         for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(vis[i][j]==false && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }



    }
};