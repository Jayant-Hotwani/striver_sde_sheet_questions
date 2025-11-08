#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of platforms required
// at the railway station such that no train waits.
// start[]: arrival times of trains
// end[]: departure times of trains
// n: number of trains
// Returns the minimum number of platforms required
// Link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
// Example:
// Input: start = {900, 940, 950, 1100,
//       end = {910, 1200, 1120, 1130}
// Output: 3
// Explanation: There are at-most three trains at a time
// at the station.
class Solution {
  public:
  
    int minPlatform(vector<int>& start, vector<int>& end) {
        // code here
         int n=start.size();
            // interesing solution 
            // sort both the arrays
            // then use two pointers to traverse the arrays
            // if start time is less than equal to end time increase platform count
            // else decrease platform count
            // keep track of maximum platform count
            // that will be the answer
            // TC: O(nlogn) SC: O(1)

            sort(start.begin(),start.end());
            sort(end.begin(),end.end());
            
            int j=0;
            int platform=1;
            int ans=1;
            // for(int i=1;i<n;i++){
            //     while (j<i && j<n && start[i]>end[j]){
            //         j++;
            //         platform--;
            //     }
            //     platform++;
            //     ans=max(ans,platform);
            // }
            
            // better way to write
            int i=1;
            while(i<n && j<n){
                if (start[i]<=end[j]){
                    platform++;
                    i++;
                }
                else{
                    platform--;
                    j++;
                }
                ans=max(ans,platform);
            }
        
            return ans;
            

            // rolling hash solution
            // TC: O(nlogn) SC: O(n)
            // using map to store the events

            map<int,int>mp;
            for(int i=0;i<n;i++){
                mp[start[i]]++;
                mp[end[i]+1]--;
            }
            int ans=0;
            int cnt=0;
            for(auto x:mp){
                cnt+=x.second;
                ans=max(ans,cnt);
            }
            return ans;


    }
};

int main() {
    Solution solution;
    vector<int> start = {900, 940, 950, 1100, 1500, 1800};
    vector<int> end = {910, 1200, 1120, 1130, 1900, 2000};
    int minPlatforms = solution.minPlatform(start, end);
    std::cout << "Minimum number of platforms required: " << minPlatforms << std::endl;
    return 0;
}