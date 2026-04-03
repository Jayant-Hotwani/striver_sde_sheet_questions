#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largest_area_in_histogram(vector<int>& nums){
        int n=nums.size();
        stack<int>st;
        vector<int>pse(n,-1);
        vector<int>nse(n,-1);

        st.push(0);
        pse[0]=-1;
        for(int i=1;i<n;i++){
            while(!st.empty() && nums[i]<=nums[st.top()]){
                st.pop();
            }
            if (!st.empty())pse[i]=st.top();
            else pse[i]=-1;

            st.push(i);
        }
        while(!st.empty())st.pop();

        st.push(n-1);
        nse[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums[i]<=nums[st.top()]){
                st.pop();
            }
            if (!st.empty())nse[i]=st.top();
            else nse[i]=-1;

            st.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            // cout<<pse[i]<<" "<<nse[i]<<endl;
            int left=pse[i];
            int right=nse[i];
            if (nse[i]==-1) right=n;
            // (right-i)+(i-left) - 1
            int width=(right-left-1);
           
            ans=max(ans,nums[i]*width);
        }
        return ans;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>column_sum(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                column_sum[i][j]=1;
                    if (i-1>=0){
                        column_sum[i][j]+=column_sum[i-1][j];
                    }
                }
            }
            
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int temp=largest_area_in_histogram(column_sum[i]);
            ans=max(ans,temp);
        }
        return ans;
    }
};