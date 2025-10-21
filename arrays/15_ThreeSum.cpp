
#include <bits/stdc++.h>
using namespace std;

// leetcode link: https://leetcode.com/problems/3sum/
// problem link: https://www.codingninjas.com/codestudio/problems/three-sum_8230792
// video link: https://www.youtube.com/watch?v=8g3l1CN1F3Y&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=14
// approach: optimal approach using sorting and two pointer technique
// time complexity: O(n^2)
// space complexity: O(1) ignoring the space required for the output
// idea: sort the array, fix one element and use two pointer technique to find the other two elements such that their sum is equal to the negative of the fixed element
// to avoid duplicates, skip the same elements while moving the pointers
// return the list of triplets
// note: also included a better solution using set to avoid duplicates but it has higher time complexity due to sorting the triplets before inserting into the set
// time complexity of better solution: O(n^2 log m) where m is the number of unique triplets
// space complexity of better solution: O(m)
// code:


class Solution {
public:

    #define ll long long 
    vector<vector<int>> threeSum(vector<int>& nums) {

        // better solution

        // int n=nums.size();
        // set<vector<int>>st;
        // for(int i=0;i<n;i++){
        //     set<int>mp;
        //     for(int j=i+1;j<n;j++){
        //         int sum=nums[i]+nums[j];
        //         int req=-1*(sum);
        //         if (mp.count(req)){
        //             vector<int>v={nums[i],nums[j],req};
        //             sort(v.begin(),v.end());
        //             st.insert(v);
        //         }ß
        //         else
        //         mp.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>>ans(st.begin(),st.end());
        // return ans;
        
        // optimal solution 
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int target=0;
        for(int i=0;i<n;i++){
            if (i>0 && nums[i]==nums[i-1]) continue;
            int low=i+1;
            int high=n-1;

            while(low<high){
                int sum=nums[i]+nums[low]+nums[high];
                if (sum>target){
                    high--;
                }
                else if (sum<target){
                    low++;
                }
                else{
                    vector<int>v={nums[i],nums[low],nums[high]};
                    ans.push_back(v);
                    while(low+1<n && nums[low]==nums[low+1]){
                        low++;
                    }
                    while(high-1>=0 && nums[high]==nums[high-1]){
                        high--;
                    }
                    low++;
                    high--;
                }
            }

        }
       return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);

    for (const auto& triplet : result) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); ++i) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    return 0;
}   