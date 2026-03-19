#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(n);
        vector<int>dist(n,INT_MAX);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        dist[src]=0;
        pq.push({0,src});
        
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int distance_till_now=x.first;
            int node=x.second;
            
            if (distance_till_now>dist[node]) continue;
            
            for(auto&[adj_node,wt]:adj[node]){
                if (wt+distance_till_now<dist[adj_node]){
                    dist[adj_node]=wt+distance_till_now;
                    pq.push({dist[adj_node],adj_node});
                }
            }
        }
        
        return dist; 
    }
};