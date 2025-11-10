#include <bits/stdc++.h>
using namespace std;
// Function to determine the largest minimum distance between cows placed in stalls.
// stalls: vector containing the positions of the stalls
// k: number of cows to be placed
// Returns the largest minimum distance possible between any two cows.
// Example usage:
// int n = 5; // number of stalls
// int k = 3; // number of cows
// vector<int> stalls = {1, 2, 8, 4, 9}; // positions of the stalls
// Solution sol;
// int largestMinDist = sol.aggressiveCows(stalls, k);
// cout << largestMinDist << endl; // Output: 3
// Time Complexity: O(N log M) where N is the number of stalls and M is the maximum distance between the farthest stalls.
// Space Complexity: O(1)   

class Solution {
  public:
  
    bool isPossible(vector<int>& stalls, int n , int k , int mid){
        int prev=stalls[0];
        k--;
        for(int i=1;i<n && k>0;i++){
            if (stalls[i]>=prev+mid){
                prev=stalls[i];
                k--;
            }
        }
        
        return k==0;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int maxd=stalls[n-1]-stalls[0];
        
        int low=0;
        int high=maxd;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if (isPossible(stalls,n,k,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        return ans;
    }
};

int main(){
    Solution sol;
    int n, k;
    cin >> n >> k;
    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }
    int result = sol.aggressiveCows(stalls, k);
    cout << result << endl;
    return 0;
}