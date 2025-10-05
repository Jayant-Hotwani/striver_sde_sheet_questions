
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// how to find that subarray with max sum

int start=-1;
int subarray_start=-1;
int subarray_end=-1;

    pair<int, pair<int, int>> maxSubArray_indices(vector<int>& nums) {
        int ans = -1e9;
        int sum = 0;
        int start = -1;
        int subarray_start = -1;
        int subarray_end = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (sum == 0) {
                start = i;
            }
            sum += nums[i];
            if (sum > ans) {
                ans = sum;
                subarray_start = start;
                subarray_end = i;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return {ans, {subarray_start, subarray_end}};
    }


// Kadane's Algorithm to find the maximum subarray sum
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=-1e9;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans=max(ans,sum);
            if (sum<0){
                sum=0;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << sol.maxSubArray(nums) << endl;
    return 0;
}