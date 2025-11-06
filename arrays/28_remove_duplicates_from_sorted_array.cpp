#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // very bad solution using extra space .. 
        // set<int>st(nums.begin(),nums.end());
        // int ans=st.size();
        // vector<int>temp(st.begin(),st.end());
        // for(int i=0;i<ans;i++){
        //     nums[i]=temp[i];
        // }
        // return ans;


        // mast solution .. 
        int j=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;    
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int newLength = solution.removeDuplicates(nums);
    
    cout << "New length: " << newLength << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}