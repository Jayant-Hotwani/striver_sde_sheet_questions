#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int orig_color=image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vis[sr][sc]=true;

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int i=x.first;
            int j=x.second;
            image[i][j]=color;
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if (ni>=0 && nj>=0 && ni<m && nj<n && vis[ni][nj]==false 
                && image[ni][nj]==orig_color){
                    q.push({ni,nj});
                    vis[ni][nj]=true;
                }
            }
        }

        return image;
    }
};