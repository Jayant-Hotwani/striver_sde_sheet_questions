#include <bits/stdc++.h>
using namespace std;
// Function to allocate minimum number of pages such that the maximum number of pages assigned to a student is minimized.
// arr: vector containing the number of pages in each book
// k: number of students
// Returns the minimum possible value of the maximum number of pages assigned to a student.
// Example usage:
// int n = 4; // number of books
// int k = 2; // number of students
// vector<int> arr = {12, 34, 67, 90}; // number of pages in each book
// Solution sol;
// int minPages = sol.findPages(arr, k);
// cout << minPages << endl; // Output: 113
// Time Complexity: O(N log S) where N is the number of books and S is the sum of all pages.
// Space Complexity: O(1)

class Solution {
  public:
    bool isValid(vector<int>& arr,int mid,int k){
        int students=1;
        int s=0;
        for(int i=0;i<arr.size();i++){
            s+=arr[i];
            if (s>mid){
                students++;
                s=arr[i];
            }
        }
        
        return students<=k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int s=0;
        int maxi=0;
        if (k>n) return -1;
        for(int i=0;i<n;i++){
            s+=arr[i];
            maxi=max(maxi,arr[i]);
        }
        
        int low=maxi;
        int high=s;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if (isValid(arr,mid,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
int main(){
    Solution sol;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = sol.findPages(arr, k);
    cout << result << endl;
    return 0;
}