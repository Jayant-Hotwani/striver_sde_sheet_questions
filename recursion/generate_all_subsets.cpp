#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void dfs(int index , vector<int>& arr, int sum , vector<int>& ans){
        if(index>=arr.size()){
            ans.push_back(sum);
            return;
        }
        
        // not pick
        dfs(index+1,arr,sum,ans);
        //pick
        dfs(index+1,arr,(sum+arr[index]),ans);
    }
    
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>ans;
        int sum=0;
        dfs(0,arr,sum,ans);
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3};
    vector<int> subsets = solution.subsetSums(arr);
    std::cout << "Subset sums: ";
    for (int sum : subsets) {
        std::cout << sum << " ";
    }
    std::cout << std::endl;
    return 0;
}
