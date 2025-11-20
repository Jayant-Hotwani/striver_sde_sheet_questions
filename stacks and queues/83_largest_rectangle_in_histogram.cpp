#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        // find next smaller to every guy .. * times guys hieght .. i think it works
        int n=nums.size();
        vector<int>smaller_on_right(n,-1);
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums[i]<=nums[st.top()]){
                st.pop();
            }
            if(!st.empty()) smaller_on_right[i]=st.top();
            st.push(i);
        }

        while(!st.empty())st.pop();

        vector<int>smaller_on_left(n,-1);
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && nums[i]<=nums[st.top()]){
                st.pop();
            }
            if(!st.empty()) smaller_on_left[i]=st.top();
            st.push(i);
        }

        for(auto x:smaller_on_left){
            cout<<x<<" ";
        }
        cout<<endl;
        for(auto x:smaller_on_right){
            cout<<x<<" ";
        }
        cout<<endl;

        int ans=0;
        for(int i=0;i<n;i++){

            int L = smaller_on_left[i];
            int R = smaller_on_right[i];

            // we can take valued from l+1 to r-1 
            // if l==-1 then we can take evrything  so l+1=0 l=-1;
            // if r==-1 we can take evrthing on right upto n-1 so r=n;

            if (L == -1) L = -1;
            if (R == -1) R = n;

            int width = R - L - 1;
            ans=max(ans,nums[i]*width);
        }
            
        return ans;
    }
};