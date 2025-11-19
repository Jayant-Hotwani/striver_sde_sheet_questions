#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }


        int time=0;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto x=q.front();
                q.pop();
                int i=x.first;
                int j=x.second;
                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if (ni>=0 && nj>=0 && ni<m && nj<n && grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        q.push({ni,nj});
                    }
                }
            }
            if (q.size()>0)
            time++;
    }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j]==1) return -1;
            }
        }
    return time;
    }
};