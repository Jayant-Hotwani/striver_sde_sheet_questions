#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        int old_n=n;
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }

        stack<int>st;
        n=nums.size();
        vector<int>temp_ans(n,-1);
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty()&& nums[i]>=nums[st.top()]){
                st.pop();
            }

            if (!st.empty()) temp_ans[i]=st.top();
            st.push(i);
        }

        vector<int>ans;
        for(int i=0;i<old_n;i++){
            if (temp_ans[i]==-1)
            ans.push_back(-1);
            else
            ans.push_back(nums[temp_ans[i]]);
        }
        return ans;
    }
};

int main(){

    return 0;
}