#include <bits/stdc++.h>
using namespace std;

// moore voting algorithm
// time complexity O(n) and space complexity O(1)
// we have to find the element which is more than n/2 times in array
// intution is if we take two different elements they will cancel each other
// so in the end we will be left with the majority element
// if we take two same elements they will increase the count of that element
// so in the end we will be left with the majority element
// if we take two different elements they will cancel each other 
// so in the end we will be left with the majority element

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // very important moore voting algorithm

        int n=nums.size();
        int ele=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if (cnt==0){
                ele=nums[i];
            }
            if(nums[i]!=ele){
                cnt--;
            }
            else{
                cnt++;
            }
            if (cnt==0){
                cnt=0;
            }
        } 
        return ele;
        
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,2,2,2,3};
    int result = sol.majorityElement(nums);
    std::cout << "Majority Element: " << result << std::endl;
    return 0;
}