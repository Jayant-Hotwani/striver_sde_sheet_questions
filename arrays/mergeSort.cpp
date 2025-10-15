#include<bits/stdc++.h>
using namespace std;

// merge sort
// time complexity O(nlogn)
// space complexity O(n)
// stable sorting algorithm
// divide and conquer algorithm
// we can use merge sort to sort a linked list in O(nlogn) time and O(1) space
// we can use merge sort to count inversions in an array in O(nlogn) time and O(n) space
// we can use merge sort to find the kth smallest element in an array in O(nlogn) time and O(n) space

class Solution {
public:
    // lets code merge sort 
    void MergeTwoSortedArrays(vector<int>& nums,int low , int mid , int high){
        // 1st array - low to mid
        // 2nd array - mid+1 to high
        vector<int>temp;
        int i=low; int j=mid+1;
        int n=mid;
        int m=high;
        while(i<=n && j<=m){
            if (nums[i]<nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=n){
                temp.push_back(nums[i]);
                i++;
        }
        while(j<=m){
                temp.push_back(nums[j]);
                j++;
        }

        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }

    void MergeSort(vector<int>& nums , int low , int high){
        if(low>=high) return ;
        int mid=low+(high-low)/2;
        MergeSort(nums,low,mid);
        MergeSort(nums,mid+1,high);
        MergeTwoSortedArrays(nums,low,mid,high);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        MergeSort(nums,0,n-1);
        return nums;
        
    }
};

int main(){
    Solution sol;
    vector<int> nums={5,2,3,1};
    vector<int> sortedArray=sol.sortArray(nums);
    for(auto x:sortedArray){
        cout<<x<<" ";
    }
    return 0;
}