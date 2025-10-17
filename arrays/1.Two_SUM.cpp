#include <bits/stdc++.h>
using namespace std;

// two sum problem
// given an array of integers nums and an integer target , return indices of the two numbers such
// that add up to target
// you may assume that each input would have exactly one solution
// you may not use the same element twice
// you can return the answer in any order               
// similar to leetcode problem
// https://leetcode.com/problems/two-sum/
// approach : using hashmap to store the elements and their indices
// time complexity : O(n) , space complexity : O(n)
// optimized approach : sort the array and use two pointers to find the two elements
// time complexity : O(nlogn) , space complexity : O(n) for storing the indices/
// we will store the elements along with their original indices in a vector of pairs
// then sort the vector and use two pointers to find the two elements
// finally return the original indices of the two elements
// time complexity : O(nlogn) , space complexity : O(n)
// code for both approaches is given below

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int>ans;
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int req=target-nums[i];
            if (mp.find(req)!=mp.end()){
                ans.push_back(mp[req]);
                ans.push_back(i);
                break;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
    vector<int> twoSumOptimized(vector<int>& nums, int target) {

        vector<int>ans;
        int n=nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int i=0;
        int j=n-1;
        while(i<j){
            if (v[i].first+v[j].first==target){
                ans.push_back(v[i].second);
                ans.push_back(v[j].second);
                return ans;
            }
            else if (v[i].first+v[j].first>target){
                j--;
            }
            else i++;
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    cout << "Indices of the two numbers that add up to " << target << " are: ";
    for (int index : result) {
        cout << index << " ";
    }
    return 0;
}