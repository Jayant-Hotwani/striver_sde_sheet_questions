#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        
        vector<int>vis(26,0);
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                vis[words[i][j]-'a']++;
            }
        }
        
        int cnt=0;
        for(int i=0;i<26;i++){
            if(vis[i]>0)cnt++;
        }
        vector<vector<int>>adj(26);
        vector<int>indeg(26,0);
        
        for(int i=0;i<words.size()-1;i++){
            bool f=true;
            string s=words[i];
            string t=words[i+1];
            for(int k=0;k<min(s.size(),t.size());k++){
                if (s[k]!=t[k]){
                    adj[s[k]-'a'].push_back(t[k]-'a');
                    indeg[t[k]-'a']++;
                    f=false;break;
                }
            }
            if (f && s.size()>t.size())return "";
        }
        
        queue<int>q;
        for(int i=0;i<26;i++){
            if (indeg[i]==0 && vis[i]>0){
                q.push(i);
            }
        }
        string topo="";
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            topo+=('a'+x);
            for(auto adj_node:adj[x]){
              
                indeg[adj_node]--;
                if (indeg[adj_node]==0){
                    q.push(adj_node);
                }
            }
        }
        
        if (topo.size()==cnt)return topo;
        return "";
    }
};