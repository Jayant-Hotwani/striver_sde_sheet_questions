#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int n, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<pair<int,int>>mst;
        int sum=0;
        // priority_queue {int,int,int}
        // wt node parent
        
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({0,{0,-1}});
        vector<int> vis(n,0);
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int wt=x.first;
            int node=x.second.first;
            int parent=x.second.second;
            if(vis[node]==1)continue;
            vis[node]=1;
            
            if (parent!=-1){
                mst.push_back({parent,node});
            }
            sum+=wt;
            for(auto& [adj_node,wt]:adj[node]){
                if (vis[adj_node]==0){
                    pq.push({wt,{adj_node,node}});
                }
            }
        }
        return sum;
    }
};