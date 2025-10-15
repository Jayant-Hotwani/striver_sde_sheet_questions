#include <bits/stdc++.h>
using namespace std;


// Count Inversions in an array
// we can do this with merge sort
// time complexity O(nlogn)
// space complexity O(n)
// an inversion is a pair of indices (i,j) such that i<j and arr[i]>arr[j]
// we can count the inversions while merging two sorted arrays
// while merging if arr[i]>arr[j] then all the elements from i to mid will be greater than arr[j]
// so we can count the inversions as mid-i+1    
// we can return the count of inversions

class Solution {
  public:
  
  // lets do this with merge sort ....
    int ans=0;
    
    void MergeTwoSortedArrays(vector<int>& nums , int low , int mid , int high){
        // arr1[low......mid]
        // arr2[mid+1...high]
        
        vector<int>temp;
        int i=low,j=mid+1;
        while(i<=mid && j<=high){
            if (nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                ans+=(mid+1-i);
                j++;
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
  
    void MergeSort(vector<int>& nums , int low , int high){
        
        if (low>=high)return ;
        int mid=low+(high-low)/2;
        MergeSort(nums,low,mid);
        MergeSort(nums,mid+1,high);
        MergeTwoSortedArrays(nums,low,mid,high);
    }
  
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        MergeSort(arr,0,n-1);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> arr={2,4,1,3,5};
    int count=sol.inversionCount(arr);
    cout<<count;
    return 0;
}