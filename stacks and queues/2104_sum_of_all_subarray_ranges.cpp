#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    #define ll long long 
    long long sum_of_all_subarray_maximums(vector<int>& nums , int n){

        // just check wheather this element can contriute 
        // to how many subarrays as maximum
        // find next greater on right and on left too 

        stack<int>st;
        vector<int>ngl(n,-1);
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && nums[i]>nums[st.top()]){
                st.pop();
            }
            if(!st.empty()) ngl[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        vector<int>ngr(n,-1);
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums[i]>=nums[st.top()]){
                st.pop();
            }
            if(!st.empty()) ngr[i]=st.top();
            st.push(i);
        }

        


        ll ans=0;
        for(int i=0;i<n;i++){
            int L=ngl[i];
            int R=ngr[i];
            if (L==-1) L=-1;
            if (R==-1) R=n;
            int left_ele=i-L;
            int right_ele=R-i;
            ll tot_subarrays=left_ele*right_ele;
            ans+=(nums[i]*tot_subarrays);
        }
        return ans;

    }

    long long sum_of_all_subarray_minimums(vector<int>& nums , int n){

        // just check wheather this element can contriute 
        // to how many subarrays as maximum
        // find next smaller on right and on left too 

        stack<int>st;
        vector<int>nsl(n,-1);
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && nums[i]<nums[st.top()]){
                st.pop();
            }
            if(!st.empty()) nsl[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();


        vector<int>nsr(n,-1);
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums[i]<=nums[st.top()]){
                st.pop();
            }
            if(!st.empty()) nsr[i]=st.top();
            st.push(i);
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            int L=nsl[i];
            int R=nsr[i];
            if (L==-1) L=-1;
            if (R==-1) R=n;
            int left_ele=i-L;
            int right_ele=R-i;
            ll tot_subarrays=left_ele*right_ele;
            ans+=(nums[i]*tot_subarrays);
        }
        return ans;
    }



    long long subArrayRanges(vector<int>& nums) {
        
        // brute force O(n2)
        long long ans=0;
        // for(int i=0;i<nums.size();i++){
        //     int mini=1e9;
        //     int maxi=-1e9;
        //     for(int j=i;j<nums.size();j++){
        //         mini=min(mini,nums[j]);
        //         maxi=max(maxi,nums[j]);
        //         // cout<<maxi<<"--"<<mini<<endl;
        //         ans+=(maxi-mini);
        //     }
        // } 
        // return ans;

        // lets do it with stack 
        // sum_of_all_subarray_maximums - sum_of_all_subarray_minimums;

        int n=nums.size();
        ans=sum_of_all_subarray_maximums(nums,n)-sum_of_all_subarray_minimums(nums,n);
        return ans;
    }
};