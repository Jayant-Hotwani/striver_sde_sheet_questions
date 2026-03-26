#include <bits/stdc++.h>
using namespace std;

class DSU{
    public:
    int n;
    vector<int>size;
    vector<int>parent;
    DSU(int n){
        this->n=n;
        size.resize(n,1);
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){
        if (node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }

    void unionBySize(int u , int v){

        int pu=findParent(u);
        int pv=findParent(v);
        if(pv==pu) return;
        if (size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int n=0,m=0;
        for(int i=0;i<stones.size();i++){
            n=max(n,stones[i][0]);
            m=max(m,stones[i][1]);
        }

        DSU ds(n+m+2);

        set<int>st;
        for(int i=0;i<stones.size();i++){
            int row=stones[i][0];
            int col=stones[i][1]+n+1;
            ds.unionBySize(row,col);
            st.insert(row);
            st.insert(col);
        }


        int cnt=0;
        for(auto x:st){
            if (ds.findParent(x)==x)cnt++;
        }
        return stones.size()-cnt; 
    }
};