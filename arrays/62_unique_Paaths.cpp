#include <bits/stdc++.h>
using namespace std;

// unique paths from top left to bottom right in a m x n grid
// only down and right moves allowed
// return number of unique paths
// similar to grid unique paths leetcode problem
// https://leetcode.com/problems/unique-paths/
// approach : dp or combinatorics
// dp approach - memoization top down
// combinatorics - total moves = m+n-2 , down moves = m-1
// so answer is (m+n-2) C (m-1) OR (m+n-2) C (n-1)
// nCr = n!/(r!*(n-r)!)
// to avoid overflow we will calculate it using multiplicative formula
// nCr = (n-r+1)/1 * (n-r+2)/2 * ... * n/r
// this will avoid overflow and give correct answer
// time complexity : O(m+n) for combinatorics approach
// space complexity : O(1) for combinatorics approach
// for dp approach time complexity : O(m*n) , space complexity : O(m*n) for dp array 


class Solution {
public:

    // memoization
    // top down approach
    // 
    int dp[101][101];
    int dfs(int i, int j , int m , int n){
        if (i==m-1 && j==n-1) return 1;
        if (i>=m || j>=n) return 0;

        if (dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        ans+=dfs(i+1,j,m,n);
        ans+=dfs(i,j+1,m,n);
        return dp[i][j]= ans;
    }

    int nCr(int n , int r){
        double res=1;
        for(int i=1;i<=r;i++){
            res=res*(n-r+i)/i;
        }
        return res;
    }

    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        // return dfs(0,0,m,n);



        // most optimal solution at mx we require n+m-2 moves and among them there will be 
        // m-1 down moves && n-1 right moves
        // so answer is n+m-2 c m-1 OR n+m-2 c n-1

        return nCr(n+m-2,m-1);
    }
};

int main() {
    Solution sol;
    int m = 3, n = 7;
    int result = sol.uniquePaths(m, n);
    cout << "Number of unique paths from top-left to bottom-right in a " << m << "x" << n << " grid is: " << result << endl;
    return 0;
}