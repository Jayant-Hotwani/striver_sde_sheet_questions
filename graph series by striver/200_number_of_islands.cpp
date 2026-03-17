#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid, vector<vector<bool>>& vis){
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() 
        || grid[i][j]=='0' || vis[i][j]==true)
        {
            return ;
        }
        vis[i][j]=true;
        dfs(i+1,j,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i,j-1,grid,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int islands=0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (vis[i][j]==false && grid[i][j]=='1'){
                    islands++;
                    dfs(i,j,grid,vis);
                }
            }
        }

        return islands;
    }
};