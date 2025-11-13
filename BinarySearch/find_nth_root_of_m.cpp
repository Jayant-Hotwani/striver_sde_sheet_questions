#include <bits/stdc++.h>
using namespace std;
// Function to find the nth root of a number m using binary search.
// n: the degree of the root
// m: the number to find the nth root of
// Returns the nth root of m if it exists, otherwise returns -1.
// Example usage:
// int n = 3; // degree of the root
// int m = 27; // number to find the root of
// Solution sol;
// int root = sol.nthRoot(n, m);
// cout << root << endl; // Output: 3
// Time Complexity: O(log m * n) where log m is for the binary search and n is for calculating mid^n.
// Space Complexity: O(1)   

class Solution {
  public:
  
    int nthRoot(int n, int m) {
        // Code here
        int low=1;
        int high=m;
        int ans=-1;
        if(m==0) return 0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int res=1;
            for(int i=1;i<=n;i++){
                res=res*mid;
            }
            if (res==m){
                return mid;
            }
            else if (res>m){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int n, m;
    cin >> n >> m;
    int result = sol.nthRoot(n, m);
    cout << result << endl;
    return 0;
}