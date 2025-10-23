#include <bits/stdc++.h>
using namespace std;


// leetcode link: https://leetcode.com/problems/reverse-pairs/
// problem link: https://www.codingninjas.com/codestudio/problems/reverse
// video link: https://www.youtube.com/watch?v=1fGea3a0c8k&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=18
// approach: merge sort based approach
// time complexity: O(n log n)
// space complexity: O(n) for temporary array used in merge step
// idea: use merge sort to sort the array, during the merge step count the number of
// reverse pairs by checking for each element in the left subarray how many elements
// in the right subarray are less than half of it.
// code:
class Solution {
public:
    #define ll long long 
    int ans=0;
    void MergeTwoSortedArrays(int low , int mid , int high , vector<int>& nums){
        // [low...mid]
        // [mid+1..high]
        vector<int>temp;
        int i=low;
        int j=mid+1;
        while(i<=mid && j<=high){
            if (nums[i]>nums[j]){
                temp.push_back(nums[j]);
                j++;
            }
            else{
                temp.push_back(nums[i]);
                i++;
            }
        }

        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }

        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }

    void countPairs(int low , int mid , int high , vector<int>& nums){
        
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && nums[i]>(ll)2*nums[right]){
                right++;
            }
            ans+=(right-(mid+1));
        }
    }

    void MergeSort(int low , int high , vector<int>& nums){
        if (low<high){
            int mid=low+(high-low)/2;
            MergeSort(low,mid,nums);
            MergeSort(mid+1,high,nums);
            countPairs(low,mid,high,nums);
            MergeTwoSortedArrays(low,mid,high,nums);
        }
    }
    int reversePairs(vector<int>& nums) {

        int n= nums.size();
        int low=0;
        int high=n-1;
        MergeSort(low,high,nums);
        return ans;
    
    }
};

int main(){
    Solution sol;
    vector<int>nums={1,3,2,3,1};
    cout<<sol.reversePairs(nums);
    return 0;
}