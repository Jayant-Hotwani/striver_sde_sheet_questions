#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int new_i, int new_j,int n,vector<vector<bool>>& vis,
        vector<vector<int>>& grid){
        
        if (new_i>=0 && new_j>=0 && new_i<n && new_j<n 
        && grid[new_i][new_j]==0 && vis[new_i][new_j]==false)return true;


        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        

        int n=grid.size();
        // we do not need priority_queue bcoz every time distance will be same in PQ 
        // as all edge weights are unit distance
        if (grid[0][0]==1 || grid[n-1][n-1]==1) return -1; 
        
        queue<pair<int,int>>q;
        q.push({0,0});
        int distance=0;
        int dx[8]={-1,1,0,0,-1,-1,1,1};
        int dy[8]={0,0,-1,1,-1,1,-1,1};
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        vis[0][0]=true;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                pair<int,int>& top=q.front();
                q.pop();
                int i=top.first;
                int j=top.second;
                
                if(i==n-1 && j==n-1){
                    distance++;
                    return distance;
                }
                for(int k=0;k<8;k++){
                    int new_i=i+dx[k];
                    int new_j=j+dy[k];
                    if (isValid(new_i,new_j,n,vis,grid)){
                        vis[new_i][new_j]=true;
                        q.push({new_i,new_j});
                    }
                }
            }
            if(q.size()>0){
                distance++;
            }
        }
        return -1;
    }
};