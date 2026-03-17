#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    
    bool hasCycle(int node , int parent , 
    vector<vector<int>>& adj , vector<bool>& vis ){
        vis[node]=true;
        
        for(auto adj_node:adj[node]){
            if (vis[adj_node]==false){
                if(hasCycle(adj_node,node,adj,vis)==true)
                return true;
            }
            else{
                if (adj_node!=parent)return true;
            }
        }
        
        return false;
    }
    bool isCycle(int n, vector<vector<int>>& edges) {
        // Code here
        vector<bool>vis(n,false);
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        for(int i=0;i<n;i++){
            if (vis[i]==false){
                if (hasCycle(i,-1,adj,vis)==true)return true;
            }
        }
        
        return false;

        // can be done by bfs also queue<pair<int,int>>q {node,parent}
        
    }
};