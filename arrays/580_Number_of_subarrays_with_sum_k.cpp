#include <bits/stdc++.h>
using namespace std;
// leetcode number of subarrays with sum k
// https://leetcode.com/problems/subarray-sum-equals-k/
// approach : using hashmap to store prefix sums and their frequencies
// for each prefix sum checking if (prefix_sum - k) exists in the hashmap
// if exists adding its frequency to the answer
// time complexity : O(n)
// space complexity : O(n)  

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int>mp;
        mp[0]++;
        int sum=0;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if (mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>nums={1,1,1};
    int k=2;
    cout<<sol.subarraySum(nums,k);
    return 0;
}