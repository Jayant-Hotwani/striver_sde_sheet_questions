#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    set<int> ans_set;
    vector<int>ans;
    int timer=0;
    
    void dfs(int node,int parent,vector<vector<int>>& adj,
             vector<int>& time_of_insertion,vector<int>& lowest_time,
             vector<int>& vis){
            
            vis[node]=1;
            time_of_insertion[node]=timer;
            lowest_time[node]=timer;
            timer++;
            int child=0;
            
            for(auto adj_node:adj[node]){
                if (adj_node==parent)continue;
                if (vis[adj_node]==0){
                    child++;
                    dfs(adj_node,node,adj,time_of_insertion,lowest_time,vis);
                    lowest_time[node]=min(lowest_time[node],lowest_time[adj_node]);
                    
                    if (parent!=-1 && lowest_time[adj_node]>=time_of_insertion[node]){
                        ans_set.insert(node);
                    }
                }
                else{
                    lowest_time[node]=min(lowest_time[node],time_of_insertion[adj_node]);
                }
                
            }
            
            if (parent==-1 && child>1){
                ans_set.insert(node);
            }      
                 
    }
    vector<int> articulationPoints(int n, vector<vector<int>>& edges) {
        // Code here
        
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int src=edges[i][0];
            int dst=edges[i][1];
            adj[src].push_back(dst);
            adj[dst].push_back(src);
        }
        
        vector<int>time_of_insertion(n);
        vector<int>lowest_time(n);
        
        for(int i=0;i<n;i++){
            if (vis[i]==0)
            dfs(i,-1,adj,time_of_insertion,lowest_time,vis);
        }
        if (ans_set.empty()) return {-1};
        // remove duplicated from ans;
        for(auto x:ans_set)ans.push_back(x);
        
        return ans;
        
    }
};