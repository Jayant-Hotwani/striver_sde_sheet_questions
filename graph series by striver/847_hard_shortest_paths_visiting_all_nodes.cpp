#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        // multi source bfs +bit mask
        int steps=0;
        int n=graph.size();
        vector<vector<int>>vis(n,vector<int>(1<<n,0));
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            adj[i]=graph[i];
        }
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            int mask=1<<i;
            q.push({i,mask});
            vis[i][mask]=true;
        }

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto x=q.front();
                q.pop();
                int curr_mask=x.second;
                int node=x.first;
                if (curr_mask==(1<<n)-1)return steps;
                for(auto adj_node:adj[node]){
                    int new_mask=curr_mask|(1<<adj_node);
                    if (vis[adj_node][new_mask]==0){
                        vis[adj_node][new_mask]=1;
                        q.push({adj_node,new_mask});
                    }
                }
            }
            if (q.size()>0)steps++;
        }
        return steps;
    }
};