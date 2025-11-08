#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findMin(int n) {
        // code here
        vector<int>v={1,2,5,10};
        int ans=0;
        while(n>0){
            for(int j=v.size()-1;j>=0;j--){
                if (n>=v[j]){
                    ans+=(n/v[j]);
                    n=n%v[j];
                }
            }
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 28; // Example amount
    int minCoins = solution.findMin(n);
    std::cout << "Minimum coins needed for " << n << ": " << minCoins << std::endl;
    return 0;
}
