#include <bits/stdc++.h>
using namespace std;
// Function to find all unique combinations in candidates where the candidate numbers sums to target
// candidates: input array of integers (may contain duplicates)
// target: target sum
// Returns a vector of vectors containing all unique combinations that sum to target
// Link: https://leetcode.com/problems/combination-sum-ii/
// Example:
// Input: candidates = [10,1,2,7,6,1,5
//         target = 8
// Output: [[1,1,6],[1,2,5],[1,7],[2,6]]
// Explanation:
// Each number in candidates may only be used once in the combination.
// To handle duplicates, we sort the array and skip over duplicate elements during the recursive calls.
// TC: O(2^n) SC: O(n) for recursion stack
// where n is the number of elements in the input array
// Note: The overall time complexity is higher due to the sorting step and the time taken to store all combinations.
// However, the dominant factor in generating combinations is O(2^n).   

class Solution {
public:
  vector<vector<int>>ans;
    void dfs(int index,vector<int>& nums, int target,vector<int>& ds){
        
        if (target==0){
            ans.push_back(ds);
        }

        for(int i=index;i<nums.size();i++){
            
            if (i!=index && nums[i]==nums[i-1]) continue;
            if (nums[i]>target) break;
            ds.push_back(nums[i]);
            dfs(i+1,nums,target-nums[i],ds);
            ds.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        // similar to subset2
       sort(nums.begin(), nums.end());   
       vector<int>ds;
       dfs(0,nums,target,ds);
       return ans;

    }
};

int main() {
    Solution solution;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> combinations = solution.combinationSum2(candidates, target);
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