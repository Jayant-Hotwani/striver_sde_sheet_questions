#include <iostream>
#include <vector>
using namespace std;

// Problem: 485. Max Consecutive Ones
// Link: https://leetcode.com/problems/max-consecutive-ones/    
// Given a binary array nums, return the maximum number of consecutive 1's in the array.
// Example:
// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3. 

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n=nums.size();
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1)cnt++;
            else{
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        ans=max(ans,cnt);
        return ans;
        
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int maxOnes = solution.findMaxConsecutiveOnes(nums);
    cout << "Max consecutive ones: " << maxOnes << endl;
    return 0;
}