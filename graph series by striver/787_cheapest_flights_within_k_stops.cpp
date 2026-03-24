#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        int stops=0;
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            adj[u].push_back({v,wt});
        }

        // we cannot implement dijistra 
        // because its concered about distance only 
        // so there could be a case
        // where at a intermediate node ,  less distance ( but more stops) is used 
        // and more distance ( but less stops ) is ingored , yielding false results

        vector<int>dist(n,1e9);
        dist[src]=0;
        queue<pair<int,int>>q;
        q.push({0,src});
        while(!q.empty()){
            int sz=q.size();
            if (stops>k)break;
            while(sz--){
                auto front_element=q.front();q.pop();
                int distance=front_element.first;
                int front_node=front_element.second;
                for(auto& [adj_node,wt]:adj[front_node]){
                    if (distance+wt<dist[adj_node]){
                        dist[adj_node]=distance+wt;
                        q.push({dist[adj_node],adj_node});
                    }
                }
            }
            if (q.size()>0){
                stops++;
            }
        }

        if(dist[dst]==1e9) return -1;


        return dist[dst];
    }
};