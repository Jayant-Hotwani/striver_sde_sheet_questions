#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int,int>mp;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 1st solution through map 

        // vector<int>ans;
        // int j=0;
        // int i=0;
        // int n=nums.size();
        // while(j<n){
        //     mp[nums[j]]++;
        //     if (j-i+1==k){
        //         auto it=mp.rbegin();
        //         ans.push_back(it->first);
        //         mp[nums[i]]--;
        //         if(mp[nums[i]]==0){
        //             mp.erase(nums[i]);
        //         }
        //         i++;
        //     }
        //     j++;
        // }
        // return ans;

        // 2ns solution through dequeue;

        deque<int>dq;
        vector<int>ans;
        int n=nums.size();
        int i=0;
        int j=0;
        while(j<n){
            while(!dq.empty() && nums[j]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            if(j-i+1==k){
                ans.push_back(dq.front());
                if (nums[i]==dq.front()){
                    dq.pop_front();
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};