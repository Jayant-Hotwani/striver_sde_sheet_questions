#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// find the duplicate number in the array
// we can do this by sorting the array and checking adjacent elements
// we can also do this by using extra space like map or hash table
// optimal way is to use binary search or tortoise and hare algorithm   
// time complexity O(nlogn) for binary search and O(n) for tortoise and hare
// space complexity O(1)


class Solution {
public:

    // naive solutions 

    // solution. 1 -> sort and check adjacent -> nlogn
    // solution 2 -> use extra space like map or hash table 

    // optimal solutions 

    // use binary search 
    // use tortoise slow fast linkedlist solution 



    int findDuplicate(vector<int>& nums) {
        
        // tortoise approach linked list slow fast pointer

        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;


        // approach 2 - binary search 
        // [1,2,3,...mid...n-1,n];
        // low =1 , high = n;
        // calculate mid and find how many elements are less than mid 
        // cnt > mid
        // move left else move right

        int n=nums.size();
        int low=1;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid)
                cnt++;
            }

            if (cnt>mid){
                high=mid-1;
            }
            else low=mid+1;
        }
            return low;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,3,4,2,2};
    cout << sol.findDuplicate(nums) << endl;
    return 0;
};