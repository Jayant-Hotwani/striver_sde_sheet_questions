#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int new_i,int new_j,int n,int m){
        if (new_i>=0 && new_j>=0 && new_i<n && new_j<m){
            return true;
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>efforts(n,vector<int>(m,1e9));
        efforts[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};

        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto top_element=pq.top();
            pq.pop();
            int effort_till_now=top_element.first;
            int i=top_element.second.first;
            int j=top_element.second.second;
            if (effort_till_now>efforts[i][j])continue;

            for(int k=0;k<4;k++){
                int new_i=i+dx[k];
                int new_j=j+dy[k];
                if (isValid(new_i,new_j,n,m)){
                    int new_effort=abs(heights[new_i][new_j]-heights[i][j]);
                    new_effort=max(new_effort,effort_till_now);
                    if (new_effort<efforts[new_i][new_j]){
                        efforts[new_i][new_j]=new_effort;
                        pq.push({new_effort,{new_i,new_j}});
                    }
                }
            }
        }
        return efforts[n-1][m-1];
    }
};