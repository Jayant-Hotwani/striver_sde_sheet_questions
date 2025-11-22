#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // similar to max area histogram
        // find all subarrays widht for which this particular element can be smallest
        // find smaller on left as L and smaller on right as R 
        // (elments_on_right*element_on_left)*arr[i];
        // (R-i)*(i-L)
        int n=arr.size();
        vector<int>sol(n,-1);
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            if(!st.empty()) sol[i]=st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        vector<int>sor(n,-1);
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(!st.empty()) sor[i]=st.top();
            st.push(i);
        }
        int mod=1e9+7;
        long long  ans=0;
        for(int i=0;i<n;i++){
            int L=sol[i];
            int R=sor[i];
            if(L==-1) L=-1;
            if(R==-1) R=n;
            // left elements
            int left_ele=i-L;
            // right elements
            int right_ele=R-i;
            long long  mul=left_ele*right_ele;
            mul=mul%mod;
            ans+=(mul*arr[i]);
            ans=ans%mod;
        }
        return ans%mod;
    }
};
