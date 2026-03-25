#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(int i , int j , int n , int m){
        if (i>=0 && j>=0 && i<n && j<m) return true;
        return false;
    }
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;

        // left -> 2 right -> 1 down ->3 up ->4 

        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
     
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        //cost , i , j
        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int cost_till_now=x.first;
            int i=x.second.first;
            int j=x.second.second;
            if (dist[i][j]<cost_till_now)continue;
            if (i==n-1 && j==m-1){
                return cost_till_now;
            }

            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if (isValid(ni,nj,n,m)){
                    int newCost=cost_till_now;
                    if(grid[i][j]!=k+1){
                        newCost++;
                    }
                    if (dist[ni][nj]>newCost){
                        dist[ni][nj]=newCost;
                        pq.push({newCost,{ni,nj}});
                    }
                }
            }
        }

        return 0;
    }
};