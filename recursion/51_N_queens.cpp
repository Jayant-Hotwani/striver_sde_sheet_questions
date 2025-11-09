#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    bool isPossible(vector<string>& v, int i , int j , int n)
    {
        // since we are filling from top to bottom and then left to right
        // for each row,we can do this by checking 3 directions only also 
        // up , upleft, upright would work ..
        
        // check in all 8 direction
        // up 
        int ti =i,tj=j;
        while(ti>=0){
            if (v[ti][tj]=='Q') return false;
            ti--;
        }
        //down
        ti=i;tj=j;
        while(ti<n){
            if (v[ti][tj]=='Q')return false;
            ti++;
        }
        //left
        ti=i;tj=j;
        while(tj>=0){
            if (v[ti][tj]=='Q') return false;
            tj--;
        }
        //right
        ti=i;tj=j;
        while(tj<n){
            if (v[ti][tj]=='Q') return false;
            tj++;
        }

        // daigonals up_left
        ti=i,tj=j;
        while(ti>=0 && tj>=0){
            if(v[ti][tj]=='Q')return false;
            ti--;tj--;
        }
        // up right
        ti=i,tj=j;
        while(ti>=0 && tj<n){
            if(v[ti][tj]=='Q')return false;
            ti--;tj++;
        }
        //down left
        ti=i;tj=j;
        while(ti<n && tj>=0)
        {
            if(v[ti][tj]=='Q')return false;
            ti++;tj--;
        }

        //down right
        ti=i;tj=j;
        while(ti<n && tj<n){
            if(v[ti][tj]=='Q')return false;
            ti++;tj++;
        }
        
        return true;
    }
    void dfs(int index , int n , vector<string>& v){
        if (index>=n){
            ans.push_back(v);
            return ;
        }

        for(int i=0;i<n;i++)
        {
            if (isPossible(v,index,i,n)){
                v[index][i]='Q';
                dfs(index+1,n,v);
                v[index][i]='.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        
        string str(n,'.');
        vector<string>v(n,str);
        dfs(0,n,v);
        return ans;
    }
};

int main(){
    Solution sol;
    int n;
    cin>>n;
    vector<vector<string>>res=sol.solveNQueens(n);
    for(auto board: res){
        for(auto row: board){
            cout<<row<<endl;
        }
        cout<<endl;
    }
    return 0;
}