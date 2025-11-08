#include <bits/stdc++.h>
using namespace std;

// Function to find all unique combinations in candidates where the candidate numbers sums to target
// candidates: input array of distinct integers
// target: target sum
// Returns a vector of vectors containing all unique combinations that sum to target
// Link: https://leetcode.com/problems/combination-sum/
// Example:
// Input: candidates = [2,3,6,7], target = 7
// Output: [[7],[2,2,3]]
// Explanation:
// 2 and 3 are used multiple times to reach the target sum of 7.
// TC: O(2^t) SC: O(t)
// where t is the target sum

class Solution {
public:
    vector<vector<int>>ans;

    void dfs(int index,vector<int>& nums, int target,vector<int>& v){
        if(index>=nums.size()){
            if (target==0){
                ans.push_back(v);
            }
            return;
        }
        // pick 
        if (index<nums.size() && target>=nums[index]){
            v.push_back(nums[index]);
            dfs(index,nums,target-nums[index],v);
            v.pop_back();
        }
        //not pick
        dfs(index+1,nums,target,v);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<int>v;
        dfs(0,nums,target,v);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> combinations = solution.combinationSum(candidates, target);
    std::cout << "Combinations that sum to " << target << ":\n";
    for (const auto& combination : combinations) {
        std::cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            std::cout << combination[i];
            if (i < combination.size() - 1) std::cout << ", ";
        }
        std::cout << "]\n";
    }
    return 0;
}
