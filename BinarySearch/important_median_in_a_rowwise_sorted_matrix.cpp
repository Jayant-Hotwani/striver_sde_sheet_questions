#include <bits/stdc++.h>
using namespace std;
// Problem: Find Median in a Row-wise Sorted Matrix
// Link: https://www.codingninjas.com/studio/problems/median-in-a-row-wise-sorted-matrix_982938
// Difficulty: Medium
// Tags: Binary Search, Matrix
class Solution {
  public:   
    // Time Complexity: O(m * log(max_element) * log(n))
    // Space Complexity: O(1)

    int bin(vector<int>& v , int target){
        int low=0;
        int high=v.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if (v[mid]<=target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
    // Function to find median in a row-wise sorted matrix
    // Approach: Binary Search
    // We perform binary search on the range of possible median values (from 0 to 1e9).
    // For each mid value, we count how many elements are less than or equal to mid
    // across all rows using a helper binary search function.   
    // If the count is greater than half the total elements, we adjust our search to the left half,
    // otherwise to the right half. The process continues until we find the median.
    int median(vector<vector<int>> &mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        int low=0;
        int high=1e9;
        
        int elements_on_left=(m*n)/2;
        while(low<=high){
            int mid=low+(high-low)/2;
            int cnt=0;
            for(int i=0;i<m;i++){
                cnt+=bin(mat[i],mid);
            }
            if (cnt>elements_on_left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout << "Median is: " << sol.median(matrix) << endl;
    return 0;
}