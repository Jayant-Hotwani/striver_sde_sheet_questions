#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// we have to buy and sell only once
// we can buy on any day and sell on any day after that
// we have to find max profit
// we can do this by finding greatest on right;
// or we can do this by finding smallest on left and max profit at each point
// and return max profit
// or we can do this without extra space by maintaining a maxi variable while travelling right to left
// and finding max profit at each point
// and return max profit
// we can also do this by maintaining a mini variable while travelling left to right
// and finding max profit at each point
// and return max profit
// time complexity O(n)
// space complexity O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // we can do this by finding greatest on right;
        int n=prices.size();
        vector<int>gr(n,-1);
        gr[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            gr[i]=max(prices[i],gr[i+1]);
        }
        int maxp=0;
        for(int i=0;i<n;i++){
            int curr=gr[i]-prices[i];
            maxp=max(maxp,curr);
        }
        return maxp;


        // we could have done this without extra space 
        // just mintain a maxi variable while travelling right to left;

        int maxprofit=0;
        int maxii=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxii=max(maxii,prices[i]);
            maxprofit=max(maxprofit,maxii-prices[i]);
            
        }
        return maxprofit;


    }
};
int main()
{
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    cout << sol.maxProfit(prices) << endl;
    return 0;
};