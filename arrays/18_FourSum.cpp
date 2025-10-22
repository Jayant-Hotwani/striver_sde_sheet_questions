#include <bits/stdc++.h>
using namespace std;


// leetcode link: https://leetcode.com/problems/4sum/
// problem link: https://www.codingninjas.com/codestudio/problems/four
// video link: https://www.youtube.com/watch?v=8g3l1CN1F3Y&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=15
// approach: optimal approach using sorting and two pointer technique
// time complexity: O(n^3)
// space complexity: O(1) ignoring the space required for the output
// idea: sort the array, fix two elements and use two pointer technique to find the other
// two elements such that their sum is equal to the target minus the sum of the fixed elements
// to avoid duplicates, skip the same elements while moving the pointers
// return the list of quadruplets
// note: also included a better solution using set to avoid duplicates but it has higher time complexity
// due to sorting the quadruplets before inserting into the set
// time complexity of better solution: O(n^3 log m) where m is the number of unique quadruplets
// space complexity of better solution: O(m)
// code:    


class Solution {
public:
#define ll long long 
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        // better solution
        set<vector<int>>unique;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<ll>st;
                for(int k=j+1;k<n;k++){
                    ll sum=nums[i]+nums[j];
                    sum+=nums[k];
                    ll req=target-sum;
                    if(st.find(req)!=st.end()){
                        vector<int>temp={nums[i],nums[j],nums[k],(int)req};
                        sort(temp.begin(),temp.end());
                        unique.insert(temp);
                    }
                    else
                    st.insert(nums[k]);
                }
            }
        }
        // vector<vector<int>>ans(unique.begin(),unique.end());
        // return ans;


        // optimal approach 
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i-1>=0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int low=j+1;
                int high=n-1;
                while(low<high){
                    ll sum=nums[i]+nums[j];
                    sum+=nums[low];
                    sum+=nums[high];
                    if (sum>target){
                        high--;
                    }
                    else if (sum<target){
                        low++;
                    }
                    else{
                        vector<int>temp={nums[i],nums[j],nums[low],nums[high]};
                        ans.push_back(temp);
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
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = sol.fourSum(nums, target);
    
    for (const auto& quad : result) {
        for (int num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}