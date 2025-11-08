#include <bits/stdc++.h>
using namespace std;

// Function to return all possible subsets of the given array
// nums: input array which may contain duplicates
// Returns a vector of vectors containing all unique subsets
// Link: https://leetcode.com/problems/subsets-ii/
// Example:
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Explanation: The solution set must not contain duplicate subsets.
// To handle duplicates, we sort the array and skip over duplicate elements during the recursive calls.
// TC: O(2^n) SC: O(n) for recursion stack
// where n is the number of elements in the input array
// Note: The overall time complexity is higher due to the sorting step and the time taken to store all subsets.
// However, the dominant factor in generating subsets is O(2^n).
// The space complexity for storing the subsets is also O(2^n) in the worst case.
// Example usage is provided in the main function below.

class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int index, vector<int>& nums , vector<int>& ds){
        ans.push_back(ds);
        for(int i=index;i<nums.size();i++){
            if (i!=index && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            dfs(i+1,nums,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        sort(nums.begin(),nums.end());
        vector<int>ds;
        dfs(0,nums,ds);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> subsets = solution.subsetsWithDup(nums);
    std::cout << "Subsets with duplicates removed:" << std::endl;
    for (const auto& subset : subsets) {
        std::cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            std::cout << subset[i];
            if (i < subset.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}