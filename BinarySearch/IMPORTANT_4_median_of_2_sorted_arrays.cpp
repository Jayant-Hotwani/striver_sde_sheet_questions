#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size();
        int n2=nums2.size();

        // better version of naive solution
        // int cnt=0;
        // int no_of_median=0;
        // if((n2+n1) % 2==0){
        //     no_of_median=2;
        // }
        // else
        // {
        //     no_of_median=1;
        // }

        // int median_index1=(n1+n2)/2;
        // int median_index2=(n1+n2)/2 -1 ;
        // int i=0;
        // int j=0;
        // // merge 2 sorted arrys;
        // int number1=-1,number2=-1;
        // while(i<n1 && j<n2){
        //     if (nums1[i]<=nums2[j]){
        //         if (cnt==median_index1)number1=nums1[i];
        //         if (cnt==median_index2)number2=nums1[i];
        //         cnt++;
        //         i++;
                
                
        //     }
        //     else{
        //         if (cnt==median_index1)number1=nums2[j];
        //         if (cnt==median_index2)number2=nums2[j];
        //         cnt++;
        //         j++;
        //     }
        // }
        // while(i<n1){
            
        //     if (cnt==median_index1)number1=nums1[i];
        //     if (cnt==median_index2)number2=nums1[i];
        //     cnt++;
        //     i++;
        // }
        // while(j<n2){
            
        //     if (cnt==median_index1)number1=nums2[j];
        //     if (cnt==median_index2)number2=nums2[j];
        //     cnt++;
        //     j++;
        // }

        // // cout<<number1<<" -- "<<number2<<endl;

        // if (no_of_median==1){
        //     return number1;
        // }
        // else{
        //     double ans=(number1+number2)/2.00;
        //     return ans;
        // }


        // most optimal aproach using binary search

        if (n1>n2) return findMedianSortedArrays(nums2,nums1);
        
        int low=0;
        int high=n1;
        while(low<=high){
            int cut1=low+(high-low)/2;
            int cut2=(n1+n2+1)/2 - cut1;

            int left1 = cut1==0 ?INT_MIN:nums1[cut1-1];
            int left2 = cut2==0 ?INT_MIN:nums2[cut2-1];

            int right1 = cut1==n1 ?INT_MAX:nums1[cut1];
            int right2 = cut2==n2 ?INT_MAX:nums2[cut2];

            if (left1<=right2 && left2<=right1){
                if ( (n1+n2) % 2 ==0)
                {
                    double ans;
                    ans=(max(left1,left2)+min(right1,right2))/2.00;
                    return ans;
                }
                else
                return double (max(left1,left2));
            }
            else if (left1>right2) high=cut1-1;
            else low=cut1+1;
        }
        return 0.00;

    }
};

int main(){
    Solution sol;
    vector<int> nums1={1,3};
    vector<int> nums2={2};
    cout<<sol.findMedianSortedArrays(nums1,nums2);
    return 0;
}