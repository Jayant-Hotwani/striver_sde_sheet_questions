// User function Template for C++
#include<bits/stdc++.h>
using namespace std;
class DSU{
    public:
    int n;
    vector<int>size;
    vector<int>parent;
    DSU(int n){
        this->n=n;
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    void unionBySize(int u , int v){
        int pu=findPar(u);
        int pv=findPar(v);
        if (pu == pv) return;

        if (size[pu]>size[pv]){
           size[pu]+=size[pv];
           parent[pv]=pu;
        }
        else{
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
    }

    int findPar(int node){
        if (node==parent[node]){
            return node;
        }
        return parent[node]=findPar(parent[node]);
    }

    int countComponents(){
        int cnt=0;
        for(int i=0;i<n;i++){
            if (i==findPar(i))cnt++;
        }
        return cnt;
    }
};

bool mycmp(vector<int>& a , vector<int>& b){
    return a[2]<b[2];
}

class Solution {
  public:
    int kruskalsMST(int n, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(),edges.end(),mycmp);
        int sum=0;
        DSU ds(n);
        for(auto it:edges){
            int u=it[0]; int v=it[1]; int wt=it[2];
            if (ds.findPar(u)!=ds.findPar(v)){
                sum+=wt;
                ds.unionBySize(u,v);
            }

        }
        return sum;
        
        
    }
};