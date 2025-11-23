#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<int>knows(n,0);
        vector<int>known_by(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]){
                    knows[i]++;
                    known_by[j]++;
                }
            }
        }
        
        int ans=-1;
        // for(auto x:known_by){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x:knows){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        
        for(int i=0;i<n;i++){
            if (known_by[i]>=n){
                if (knows[i]==1){
                    ans=i;
                    break;
                }
            }
        }
        
        return ans;
        
    }
};