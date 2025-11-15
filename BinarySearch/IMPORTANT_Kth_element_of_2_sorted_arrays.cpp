#include <bits/stdc++.h>
using namespace std;
// Problem: Kth Element of 2 Sorted Arrays
// Link: https://www.codingninjas.com/studio/problems/kth-element-of-
//two-sorted-arrays_975379
// Difficulty: Hard
// Tags: Binary Search, Array, Divide and Conquer

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n1=a.size(); 
        int n2=b.size();
        // int cnt=0;
        // int i=0,j=0;
        // while(i<n1 && j<n2){
        //     if(a[i]<b[j]){
        //         cnt++;
        //         if(cnt==k)
        //         return a[i];
                
        //         i++;
        //     }
        //     else{
        //         cnt++;
        //         if(cnt==k)
        //         return b[j];
                
        //         j++;
        //     }
        // }
        
        // while (i<n1){
        //         cnt++;
        //         if(cnt==k)
        //         return a[i];
        //         i++;
        // }
        // while (j<n2){
        //         cnt++;
        //         if(cnt==k)
        //         return b[j];
        //         j++;
        // }
        
        // return -1;
        
        
        // most optimal binary search .. similar to median 
        // of 2 sorted arrays
        // always do binary search on smaller array
        // partitioning both arrays such that
        // left side contains k elements
        // then check for correct partitioning
        // if correct return max of left side
        // else adjust binary search accordingly
        // replace k with (n1+1+n2+1)/2 for median finding previously solved
        // problem
        if(n1>n2) return kthElement(b, a,k);
        int low = max((k-n2),0);
        int high = min(k,n1);
        
        while(low<=high){
            int cut1=low+(high-low)/2;
            int cut2=k-cut1;
            
            int left1=cut1==0?INT_MIN:a[cut1-1];
            int left2=cut2==0?INT_MIN:b[cut2-1];
            int right1=cut1==n1?INT_MAX:a[cut1];
            int right2=cut2==n2?INT_MAX:b[cut2];
            if (left1<=right2 && left2<=right1){
                return max(left1,left2);
            }
            else if (left1<right2){
                low=cut1+1;
            }
            else{
                high=cut1-1;
            }
        }
        return 0;      
    }
};

int main(){
    Solution sol;
    vector<int> a={2,3,6,7,9};
    vector<int> b={1,4,8,10};
    int k=5;
    cout<<sol.kthElement(a,b,k);
    return 0;
}