#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void topo(int node, vector<vector<int>>adj,
    stack<int>& st , vector<int>& vis){
        vis[node]=1;
        for(auto x:adj[node]){
            if (vis[x]==0){
                topo(x,adj,st,vis);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int n, vector<vector<int>>& edges) {
        // code here
        stack<int>st;
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        
        for(int i=0;i<n;i++){
            if (vis[i]==0){
                topo(i,adj,st,vis);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};