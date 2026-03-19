#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    
        vector<int>ans;
        
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        vector<int>dist(n+1,1e9);
        
        dist[1]=0;
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int dis=x.first;
            int node=x.second;
            if(dis>dist[node])continue;
            for(auto& [adj_node,wt]:adj[node]){
                if(dis+wt<dist[adj_node]){
                    dist[adj_node]=dis+wt;
                    parent[adj_node]=node;
                    pq.push({dist[adj_node],adj_node});
                }
            }
        }
        
        
        
        if(dist[n]==1e9){
            return {-1};
        }
        
        int node=n;
        while(node!=parent[node]){
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(1);
        ans.push_back(dist[n]);
        reverse (ans.begin(),ans.end());
        
        return ans;
        
    }
};