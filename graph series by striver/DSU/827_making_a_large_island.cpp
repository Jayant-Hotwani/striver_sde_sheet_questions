#include <bits/stdc++.h>
using namespace std;
class DSU{
    public:
    int n;
    vector<int>size;
    vector<int>parent;
    DSU(int n){
        this->n=n;
        size.assign(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findPar(int node){
        if(node==parent[node])return node;
        return parent[node]=findPar(parent[node]);
    }

    void unionBySize(int u , int v){
        int pu=findPar(u);
        int pv=findPar(v);
        if(pu==pv) return;
        if(size[pu]>=size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
    int countComponents(){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(i==findPar(i))cnt++;
            }
            return cnt;
        }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) { 

        int n=grid.size();
        int total=n*n;
        DSU ds(total);

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        int ones=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ones++;
                    for(int k=0;k<4;k++){
                        int ni=i+dx[k];
                        int nj=j+dy[k];
                        if (ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj]){
                            int old_node=(i*n)+j;
                            int new_node=(ni*n)+nj;
                            if (ds.findPar(new_node)!=ds.findPar(old_node))
                            ds.unionBySize(new_node,old_node);
                        }
                    }
                }
            }
        }
        if (ones==(n*n))return ones;

        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if (grid[i][j]==0){
                    set<int>parent;
                    int temp=1;
                    // check for all 4 directions 
                    for(int k=0;k<4;k++){
                        int ni=i+dx[k];
                        int nj=j+dy[k];
                        if (ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj]==1){
                            int new_node=(ni*n)+nj;
                            int par=ds.findPar(new_node);
                            if (parent.count(par)==0){
                                temp+=ds.size[par];
                                parent.insert(par);
                            }   
                        }
                    }
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};