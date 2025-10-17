#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // at max we can have 2 elemets in answer
        // moore voting algo - part2 

        int cnt1=0;
        int cnt2=0;
        long long int ele1=1e10;
        long long int ele2=1e10;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=ele2){
                ele1=nums[i];
                cnt1++;
            }
            else if (cnt2==0 && nums[i]!=ele1){
                ele2=nums[i];
                cnt2++;
            }
            else if (nums[i]==ele1) cnt1++;
            else if (nums[i]==ele2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        int req=n/3;
        req++;
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1) c1++;
            if(nums[i]==ele2) c2++;
        }
        vector<int>ans;
        if(c1>=req) ans.push_back(ele1);
        if(c2>=req) ans.push_back(ele2);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,2,3};
    vector<int> result = sol.majorityElement(nums);
    cout << "Majority elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout<<endl;
    return 0;
}