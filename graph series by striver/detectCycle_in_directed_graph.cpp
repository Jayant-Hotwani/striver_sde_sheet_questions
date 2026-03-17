#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool detectCycle(int node,vector<vector<int>>& adj, int n,
                    vector<int>& vis , vector<int>& pathVis){
                        
        vis[node]=1;
        pathVis[node]=1;
        for(auto x:adj[node]){
            if (vis[x]==0){
                if (detectCycle(x,adj,n,vis,pathVis))return true;
            }
            else{
                if (pathVis[x]==1)return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
    bool isCyclic(int n, vector<vector<int>> &edges) {
        // code here
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        
        
        for(int i=0;i<n;i++){
            if (vis[i]==0){
                if(detectCycle(i,adj,n,vis,pathVis)==true)
                return true;
            }
        }
        
        return false;
        
        
        
        
        
    }
};