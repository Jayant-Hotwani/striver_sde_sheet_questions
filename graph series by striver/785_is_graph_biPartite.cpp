#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node ,vector<vector<int>>& adj, vector<bool>&vis, vector<int>& color , int c){
        color[node]=c;
        vis[node]=true;
        for(auto x:adj[node]){
            if (color[x]==-1){
                 if (!dfs(x, adj, vis,color, 1 - c))
                return false;
            }
            else{
                if (color[x]==c)return false;
            }
        }

        return true;
    }

    bool bfs(int node , vector<vector<int>>& adj,vector<bool>& vis , vector<int>& color){
        queue<int>q;
        q.push(node);
        color[node]=0;
        vis[node]=true;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(auto adj_node:adj[x]){
                if (color[adj_node]==-1){
                    color[adj_node]=1-color[x];
                    q.push(adj_node);
                    vis[adj_node]=true;
                }
                else{
                    if(color[adj_node]==color[x])
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            adj[i]=graph[i];
        }
        vector<int>color(n,-1);
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if (vis[i]==false){
                if (bfs(i,adj,vis,color)==false) return false;
            }
        }
        return true;
    }
};