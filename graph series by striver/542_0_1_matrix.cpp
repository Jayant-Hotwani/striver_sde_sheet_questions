#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans=mat;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        
        int dist=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto x=q.front();
                q.pop();
                int i=x.first;
                int j=x.second;
                ans[i][j]=dist;
                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if (ni>=0 && nj>=0 && ni<n && nj<m && mat[ni][nj]==1){
                        q.push({ni,nj});
                        mat[ni][nj]=0;
                    }
                }
            }
            if (q.size()>0)
                dist++;
        }
        
        return ans;
    }
};