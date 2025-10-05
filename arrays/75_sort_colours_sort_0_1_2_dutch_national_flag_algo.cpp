
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:

    // dutch national flag algorithm 
    // intution is 
    //[0...low-1] =0 
    //[low...mid-1]=1
    //[mid...high-1]=unsorted
    //[high....n]=2;

    // if nums[mid]==0 swap with first one i.e low  index , move low++ and mid++;
    // if nums[mid]==1 , already sorted just move mid++;
    // if (nums[mid]==2) , swap with first 2 on right i.e high , reduce high-- 
    // but dont move mid , bcox after swapping it can be o and 1 both 


    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            if (nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid]==1){
                mid++;
            }
            else
            {
                swap(nums[high],nums[mid]);
                high--;
            }
        }
        
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,0,2,1,1,0};
    sol.sortColors(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}
