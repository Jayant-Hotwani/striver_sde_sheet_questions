#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs( int i , int j , vector<vector<int>>& grid, vector<vector<bool>>& vis){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() 
        || vis[i][j]==true || grid[i][j]==0) return ;

        vis[i][j]=true;
        dfs(i+1,j,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i,j-1,grid,vis);

    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (i==0 || j==0 || i==m-1 || j==n-1){
                    if (grid[i][j]==1 && vis[i][j]==false){
                        dfs(i,j,grid,vis);
                    }
                }
            }
        }

        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (vis[i][j]==false && grid[i][j]==1)ans++;
            }
        }


        return ans;
    }
};