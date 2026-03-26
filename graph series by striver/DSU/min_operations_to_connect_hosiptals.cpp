#include <bits/stdc++.h>
using namespace std;

class DSU{
  public:
  int nodes;
  vector<int>parent;
  vector<int>size;
  DSU(int n){
      this->nodes=n;
      size.resize(n,1);
      parent.resize(n,0);
      for(int i=0;i<n;i++)
      parent[i]=i;
  }
  
  int findParent(int node){
      if (node==parent[node])return node;
      return parent[node]=findParent(parent[node]);
  }
  
  void unionBySize(int u , int v){
      int par_u=findParent(u);
      int par_v=findParent(v);
      if (par_u==par_v) return ;
      if(size[par_u]>size[par_v]){
          size[par_u]+=size[par_v];
          parent[par_v]=par_u;
      }
      else{
          size[par_v]+=size[par_u];
          parent[par_u]=par_v;
      }
  }
  
  int countComponent(){
      int cnt=0;
      for(int i=0;i<nodes;i++){
          if(i==findParent(i))cnt++;
      }
      return cnt;
  }
  
};

class Solution {
  public:
    int minConnect(int n, vector<vector<int>>& edges) {
        // Code here
        if(edges.size()<n-1) return -1;
        DSU ds(n);
        int extra=0;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(ds.findParent(u)!=ds.findParent(v))
            ds.unionBySize(u,v);
            else
            extra++;
        }
        
        int req= ds.countComponent()-1;
        if (extra >= req) return req;
        return -1;    
        
    }
};
