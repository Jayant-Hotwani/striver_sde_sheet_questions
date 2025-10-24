#include <bits/stdc++.h>
using namespace std;
// leetcode count subarrays with xor k
// https://leetcode.com/problems/count-subarrays-with-xor-equal-to-k/               
// approach : using hashmap to store prefix xors and their frequencies
// for each prefix xor checking if (prefix_xor ^ k) exists in the hashmap
// if exists adding its frequency to the answer
// time complexity : O(n)
// space complexity : O(n)

class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {

        unordered_map<int,int>mp;
        mp[0]++;
        int ans=0;
        int xoro=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            xoro=xoro^nums[i];
            if (mp.find(xoro^k)!=mp.end()){
                ans+=mp[xoro^k];
            }
            mp[xoro]++;
        }

        return ans;
        
    }
};

int main(){
    Solution sol;
    vector<int>nums={4,2,2,6,4};
    int k=6;
    cout<<sol.subarraysWithXorK(nums,k);
    return 0;
}