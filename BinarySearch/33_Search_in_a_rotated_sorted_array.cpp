
#include <bits/stdc++.h>
using namespace std;

// Problem: Search in Rotated Sorted Array
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Difficulty: Medium
// Tags: Array, Binary Search
class Solution {
public:
    // Time Complexity: O(log n)
    // Space Complexity: O(1)   
    int search(vector<int>& nums, int target) {

        // at any point of time 
        // either of the lef half or right half would be sorted
        // just check wheater our target lies in that range

        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            if (nums[low]<=nums[mid]){
                //left half sorted
                if (target>=nums[low] && target<=nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                // right half sorted
                if (target>=nums[mid] && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }

        return -1;
        
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,3,5,7,9,11,13};
    int target=0;
    cout<<sol.search(nums,target);
    return 0;
}