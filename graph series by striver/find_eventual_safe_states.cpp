#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        // reverse the edges 
        int n=graph.size();
        vector<int>indeg(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
                indeg[i]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if (indeg[i]==0)
            q.push(i);
        }

        vector<int>topo;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            topo.push_back(x);
            for(auto adj_node:adj[x]){
                indeg[adj_node]--;
                if (indeg[adj_node]==0){
                    q.push(adj_node);
                }
            }
        }

        sort(topo.begin(),topo.end());
        return topo;

    }
};