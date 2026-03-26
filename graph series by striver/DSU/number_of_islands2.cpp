#include <bits/stdc++.h>
using namespace std;

class DSU{
    public:
    int nodes;
    vector<int>size;
    vector<int>parent;

    DSU(int n){
        this->nodes=n;
        size.resize(n,1);
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){
        if(node==parent[node])return node;
        return parent[node]=findParent(parent[node]);
    }

    void unionBySize(int u , int v){
        int par_u=findParent(u);
        int par_v=findParent(v);
        if (par_u==par_v) return;
        if(size[par_u]>size[par_v]){
            size[par_u]+=size[par_v];
            parent[par_v]=par_u;
        }
        else{
            size[par_v]+=size[par_u];
            parent[par_u]=par_v;
        }
    }

    int countComponents(){
        int cnt=0;
        for(int i=0;i<nodes;i++){
            if (i==findParent(i))cnt++;
        }
        return cnt;
    }
};


class Solution {
  public:
    vector<int> numOfIslands(int n, int m, 
    vector<vector<int>> &operators) {
        // code here
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        
        int total=n*m;
        DSU ds(total);
        vector<int>ans;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<operators.size();i++){
            int u=operators[i][0];
            int v=operators[i][1];
            if (vis[u][v]==1){
                ans.push_back(cnt);
            }
            else{
                cnt++;
                vis[u][v]=1;
                for(int k=0;k<4;k++){
                    int new_u=u+dx[k];
                    int new_v=v+dy[k];
                    if (new_u>=0 && new_v>=0 && 
                    new_u<n && new_v<m && vis[new_u][new_v]==1){
                        
                        int old_node=u*m+v;
                        int new_node=new_u*m+new_v;
                        if (ds.findParent(old_node)!=ds.findParent(new_node)){
                            cnt--;
                            ds.unionBySize(old_node,new_node);
                        }
                        
                    }
                }
                ans.push_back(cnt);
            }
        }
        return ans;
    }
};
