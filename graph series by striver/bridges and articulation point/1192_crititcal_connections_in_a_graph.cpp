#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int timer=0;
    vector<vector<int>>ans;
    void dfs(int node,int parent,vector<vector<int>>& adj,vector<int>& time_of_insertion,
             vector<int>& lowest_time , vector<int>& vis){
    
        vis[node]=1;
        time_of_insertion[node]=timer;
        lowest_time[node]=timer;
        timer++;

        for(auto adj_node:adj[node]){
            if(adj_node==parent) continue;
            if (vis[adj_node]==0){
                dfs(adj_node,node,adj,time_of_insertion,lowest_time,vis);
                lowest_time[node]=min(lowest_time[node],lowest_time[adj_node]); 
                // now check for bridge
                // its not a bride is low[adj]<time[node]
                if (lowest_time[adj_node]>time_of_insertion[node]){
                    ans.push_back({node,adj_node});
                }
            }
            else{
                // can never be a bridge/critical connection bcoz we have 
                // already   visited in some other path 
                // so just take lowest time
                lowest_time[node]=min(lowest_time[node],lowest_time[adj_node]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<int>time_of_insertion(n);
        vector<int>lowest_time(n);
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);

        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if (vis[i]==0){
                dfs(i,-1,adj,time_of_insertion,lowest_time,vis);
            }
        }
        return ans; 
    }
};