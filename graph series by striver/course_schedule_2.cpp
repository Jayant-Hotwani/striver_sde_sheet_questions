#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& graph) {
        
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(int i=0;i<graph.size();i++){
            int u=graph[i][1];
            int v=graph[i][0];
            adj[u].push_back(v);
            indeg[v]++;
        }


        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)
            q.push(i);
        }

        vector<int>topo;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            topo.push_back(x);
            for(auto it:adj[x]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }

        if(topo.size()==n) return topo;
        else return {};
    }
};