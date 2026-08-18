#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>res;
    vector<int>count;
    vector<vector<int>>adj;
    int n;

    void dfs1(int node , int parent){
        for(auto adj_node:adj[node]){
            if (adj_node==parent)continue;
            dfs1(adj_node,node);
            count[node]+=count[adj_node];
            res[node]+=(res[adj_node]+count[adj_node]);
        }
    }

    void dfs2(int node , int parent){
        for(auto adj_node:adj[node]){
            if (adj_node==parent)continue;
            res[adj_node]=res[node]-count[adj_node]+(n-count[adj_node]);
            dfs2(adj_node,node);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        this->n = n;
        adj.resize(n);
        count.assign(n, 1);
        res.assign(n, 0);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs1(0,-1);
        dfs2(0,-1);

        return res;
    }
};