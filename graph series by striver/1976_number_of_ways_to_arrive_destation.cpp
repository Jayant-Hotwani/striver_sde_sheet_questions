#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define ll long long 
    ll mod=1e9+7;

    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<ll>dist(n,1e15);
        dist[0]=0;
        vector<ll>ways(n,0);
        ways[0]=1;

        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto top_element=pq.top();
            pq.pop();
            ll distance_till_now=top_element.first;
            ll node=top_element.second;
            if (distance_till_now>dist[node])continue;
            for(auto& [adj_node,wt]:adj[node]){
                if (distance_till_now+wt<dist[adj_node]){
                    dist[adj_node]=distance_till_now+wt;
                    pq.push({dist[adj_node],adj_node});
                    ways[adj_node]=ways[node];
                    ways[adj_node]%=mod;
                }
                else if (distance_till_now+wt==dist[adj_node]){
                    ways[adj_node]+=ways[node];
                    ways[adj_node]%=mod;
                }
            }
        }
        
        return ways[n-1]%mod;
    }
};