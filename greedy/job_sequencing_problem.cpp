#include <bits/stdc++.h>
using namespace std;

//
// Function to find the maximum profit and the number of jobs done
// d[]: deadlines of jobs
// p[]: profits of jobs
// Returns a vector containing the number of jobs done and the maximum profit
// Link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-
// Example:
// Input: deadlines = {2, 1, 2, 1, 3}
//        profits = {100, 19, 27, 25, 15}
// Output: {3, 142}
// Explanation: Jobs 1, 3 and 4 are selected with total profit 100 + 27 + 15 = 142  
class Solution {
  public:
    
    vector<int> jobSequencing(vector<int> &d, vector<int> &p) {
        // code here
        int n=d.size();
        int time=0;
        int maxi=0;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({p[i],d[i]});
            maxi=max(maxi,d[i]);
        }
        vector<int>slot(maxi+1,-1);
        sort(v.rbegin(),v.rend());
        
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            int time=v[i].second;
            int profit=v[i].first;
            for(int j=time;j>0;j--){
                if (slot[j]==-1){
                    slot[j]=profit;
                    ans+=profit;
                    cnt++;
                    break;
                }
            }
        }
        
        return {cnt,ans};
        
    }
};

int main() {
    Solution solution;
    vector<int> deadlines = {2, 1, 2, 1, 3};
    vector<int> profits = {100, 19, 27, 25, 15};
    vector<int> result = solution.jobSequencing(deadlines, profits);
    std::cout << "Number of jobs done: " << result[0] << ", Total profit: " << result[1] << std::endl;
    return 0;
}