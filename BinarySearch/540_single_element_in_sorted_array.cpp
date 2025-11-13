#include <bits/stdc++.h>
using namespace std;
// Function to find the single element in a sorted array where every other element appears twice.
// nums: sorted vector of integers
// Returns the single non-duplicate element.
// Example usage:
// vector<int> nums = {1,1,2,3,3,4,4,8,8};
// Solution sol;
// int singleElement = sol.singleNonDuplicate(nums);
// cout << singleElement << endl; // Output: 2  

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        

        // naive appraoch map / set / hashing

        // better approach without space do xorr

        // int xorr=nums[0];
        // for(int i=1;i<nums.size();i++){
        //     xorr=xorr^nums[i];
        // }
        // return xorr;


        // best approach binary search since sorted 

        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if (mid%2==0){
                // that means mid is even .. that means to left of mid we have even 
                // including mid it becomes odd
                // so if nums[mid]==nums[mid-1] .. we can say culprit on left
                // otherwise if not equal then on right
                if (mid-1>=0 && nums[mid]==nums[mid-1]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                // that means mid is odd .. that means to left of mid we have odd 
                // including mid it becomes even
                // so if nums[mid]==nums[mid+1] .. we can say culprit on left
                // otherwise if not equal then on right
                if (mid+1<n && nums[mid]==nums[mid+1]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return nums[high];
    }
};

int main(){
    Solution sol;
    int n=5;
    vector<int> nums={1,1,2,3,3};
    int result = sol.singleNonDuplicate(nums);
    cout << result << endl;
    return 0;
}