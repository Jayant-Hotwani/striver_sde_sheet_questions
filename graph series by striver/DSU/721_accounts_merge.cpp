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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DSU ds(n);
        vector<vector<string>>ans;
        map<string,int>mp;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if (mp.find(email)==mp.end()){
                    mp[email]=i;
                }
                else{
                     ds.unionBySize(i,mp[email]);
                }
            }
        }

        vector<vector<string>>v(n);
        for(auto x:mp){
            int node=x.second;
            string email=x.first;
            int parent_node=ds.findParent(node);
            v[parent_node].push_back(email);
        }

        for(int i=0;i<n;i++){
            vector<string>temp=v[i];
            if (temp.size()==0) continue;
            sort(temp.begin(),temp.end());
            temp.insert(temp.begin(),accounts[i][0]);
            ans.push_back(temp);
        }
        return ans;
    }
};