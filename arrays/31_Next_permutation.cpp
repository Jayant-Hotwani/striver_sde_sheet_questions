#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int index=-1;
        int n=nums.size();

        // step1 find the break point where adjacent right element is greater 
        for(int i=n-2;i>=0;i--){
            if (nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
       
        if (index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
         // swap with least value on left 
        for(int i=n-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        // sort remaining on left in asc order
        sort(nums.begin()+index+1,nums.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2,4, 3};
    sol.nextPermutation(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}
