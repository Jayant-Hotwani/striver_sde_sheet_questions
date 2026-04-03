#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int>dp1(n,1),dp2(n,1);
        for(int index=0;index<n;index++){
            for(int prev=0;prev<index;prev++){
                if (nums[index]>nums[prev] && dp1[index]<1+dp1[prev]){
                    dp1[index]=1+dp1[prev];
                }
            }
        }
        
        
        for(int index=n-1;index>=0;index--){
            for(int prev=n-1;prev>index;prev--){
                if (nums[index]>nums[prev] && dp2[index]<1+dp2[prev]){
                    dp2[index]=1+dp2[prev];
                }
            }
        }
        
        int ans=0;
        for(int index=0;index<n;index++){
            if (dp1[index]>1 && dp2[index]>1)
            ans=max(ans,dp1[index]+dp2[index]-1);
        }
        return ans;
    }
};
