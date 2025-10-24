#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
#include <bits/stdc++.h>


// leetcode 128 longest consecutive subsequence
// https://leetcode.com/problems/longest-consecutive-sequence/
// approach : sorting and then counting consecutive elements
// optimal approach : using hashset to store elements and then for each element checking if its predecessor exists or not
// if not then counting all consecutive elements starting from that element 
// and updating the maximum count accordingly
 // time complexity : O(n) average case
// space complexity : O(n) 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // better 
        if (nums.size()==0) return 0;
        int n=nums.size();
        // sort(nums.begin(),nums.end());
        // int last_element=-1e9;
        // int ans=1;
        // int curr_count=0;
        // for(int i=0;i<n;i++){
        //     if (last_element==nums[i]-1)
        //     {
        //         curr_count+=1;
        //         last_element=nums[i];
        //     }else
        //     {
        //         if (last_element!=nums[i]){
        //             curr_count=1;
        //             last_element=nums[i];
        //         }
        //     }
        //     ans=max(ans,curr_count);
        // }
        // return ans;

        
        // optimal 

        unordered_set<int>st(nums.begin(),nums.end());
        int ans=1;
        for(auto it :st){
            if(st.find(it-1)==st.end()){
                int cnt=0; int num=it;
                while(st.find(num)!=st.end()){
                    num++;
                    cnt++;
                }
                ans=max(ans,cnt);
            }
        }

        return ans;

    }
};

int main(){
    Solution sol;
    vector<int>nums={100,4,200,1,3,2};
    cout<<sol.longestConsecutive(nums);
    return 0;
}