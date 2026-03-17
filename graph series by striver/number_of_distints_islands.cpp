// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    set<vector<pair<int,int>>>st;
    void dfs(int i  , int j , vector<vector<int>>& grid ,
    vector<vector<bool>>& vis, int start_i , int start_j,
    vector<pair<int,int>>& v){
        if (i<0 || j<0 || i>=grid.size() ||j>=grid[0].size()
        || vis[i][j]==true || grid[i][j]==0)
        {
            return ;
        }
        vis[i][j]=true;
        v.push_back({i-start_i,j-start_j});
        dfs(i+1,j,grid,vis,start_i,start_j,v);
        dfs(i,j+1,grid,vis,start_i,start_j,v);
        dfs(i-1,j,grid,vis,start_i,start_j,v);
        dfs(i,j-1,grid,vis,start_i,start_j,v);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if (vis[i][j]==false && grid[i][j]==1){
                    vector<pair<int,int>>v;
                    dfs(i,j,grid,vis,i,j,v);
                    st.insert(v);
                }
            }
        }        
        return st.size();
    }
};
