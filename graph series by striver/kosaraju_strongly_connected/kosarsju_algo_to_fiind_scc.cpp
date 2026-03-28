#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    void dfs1(int node ,vector<vector<int>>& adj,
    stack<int>& st , vector<int>& vis){
        vis[node]=1;
        for(auto x:adj[node]){
            if (vis[x]==0)
            dfs1(x,adj,st,vis);
        }
        st.push(node);
    }
    
    void dfs2(int node ,vector<vector<int>>& adjT,
    vector<int>& vis){
        vis[node]=1;
        for(auto x:adjT[node]){
            if (vis[x]==0)
            dfs2(x,adjT,vis);
        }
    }
    
    
    
    int kosaraju(int n, vector<vector<int>> &edges) {
        // code here
        int scc=0;
        vector<vector<int>>adj(n);
        vector<vector<int>>adjT(n);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adjT[v].push_back(u);
        }
        stack<int>st;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
           if (vis[i]==0){
               dfs1(i,adj,st,vis);
           } 
        }
        
        vis.assign(n,0);
        
        while(!st.empty()){
            auto x=st.top();
            st.pop();
            if (vis[x]==0){
                scc++;
                dfs2(x,adjT,vis);
            }
        }
        
        
        return scc;
        
    }
};