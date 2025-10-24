#include <bits/stdc++.h>
using namespace std;
// leetcode longest subarray with sum k
// https://leetcode.com/problems/longest-subarray-with-sum-k/
// approach : using hashmap to store prefix sums and their first occurrence index
// for each prefix sum checking if (prefix_sum - k) exists in the hashmap
// if exists updating the maximum length of subarray accordingly
// time complexity : O(n)
// space complexity : O(n)

// optimal - two pointer approach works only for non-negative numbers
// but here we are using hashmap approach which works for negative numbers as well 

class Solution {
  public:
  
    #define ll long long 
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        ll ans=0;
        unordered_map<ll,int>mp;
        ll sum=0;
        ll n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if (sum==k){
                ans=max(ans,(ll)i+1);
            }
            if (mp.find(sum-k)!=mp.end()){
                ans=max(ans,(ll)i-mp[sum-k]);
            }
            
            if (mp.find(sum)==mp.end())
            mp[sum]=i;
        }
        return ans;

        // 2 pointer approach - works only for non-negative numbers
        /* int left=0; int right=0;
        ll sum=0;
        ll n=arr.size();
        ll ans=0;
        while(right<n){
            sum+=arr[right];
            while(sum>k){
                sum-=arr[left];
                left++;
            }
            if(sum==k){
                ans=max(ans,right-left+1);
            }
            right++;
        }
        return ans;*/
    }

};

int main(){
    Solution sol;
    vector<int>arr={10,5,2,7,1,9};
    int k=15;
    cout<<sol.longestSubarray(arr,k);
    return 0;
}