#include <bits/stdc++.h>
using namespace std;

// Function to generate all permutations of a given array
// nums: input array of distinct integers
// Returns a vector of vectors containing all permutations of nums
// Link: https://leetcode.com/problems/permutations/
// Example:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// ,3],[2,3,1],[3,1,2],[3,2,1]]
// Explanation: There are a total of 3! = 6 permutations.   
// TC: O(n*n!) SC: O(n)
// where n is the number of elements in the input array

class Solution {
public:
    vector<vector<int>>ans;

    // Function to generate permutations using backtracking
    // nums: input array
    // n: size of the input array
    // vis: vector to keep track of visited elements
    // ds: current permutation being formed

    void dfs(vector<int>& nums , int n , 
    vector<int>& vis,vector<int>& ds){
        if (ds.size()==n){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<n;i++){
            if (vis[i]==0){
                ds.push_back(nums[i]);
                vis[i]=1;
                dfs(nums,n,vis,ds);
                ds.pop_back();
                vis[i]=0;
            }
        }
    }



    // better method that uses swapping .. so no extra space requires
    // to keep track of visited elements
    // TC: O(n*n!) SC: O(n) for recursion stack
    // where n is the number of elements in the input array
    // Note: The overall time complexity is O(n*n!) because there are n! permutations
    // and generating each permutation takes O(n) time due to the swaps and recursive calls.
    // The space complexity is O(n) for the recursion stack in the worst case.
    // Example usage is provided in the main function below.
    void dfs_optimal(int index, vector<int>& nums , int n){
        if (index>=n){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<n;i++){
            swap(nums[index],nums[i]);
            dfs_optimal(index+1,nums,n);
            swap(nums[index],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        int n=nums.size();
        // vector<int>vis(n,0);
        // vector<int>ds;
        // dfs(nums,n,vis,ds);
        // return ans;

        dfs_optimal(0,nums,n);
        return ans;
        
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = solution.permute(nums);
    std::cout << "All permutations of the array:" << std::endl;
    for (const auto& permutation : permutations) {
        std::cout << "[";
        for (size_t i = 0; i < permutation.size(); ++i) {
            std::cout << permutation[i];
            if (i < permutation.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}