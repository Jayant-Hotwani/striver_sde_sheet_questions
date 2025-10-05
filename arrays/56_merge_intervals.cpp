#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

// merge the overlapping intervals
// we can do this by sorting the intervals based on start time
// then we can iterate through the intervals and check if the current interval's start time is less than or equal to the previous interval's end time
// if yes then we can merge the intervals
// if no then we can add the previous interval to the answer and update the previous interval to the current interval
// finally we can add the last interval to the answer
// time complexity O(nlogn) for sorting + O(n) for iterating through the intervals
// space complexity O(n) for storing the answer     

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());

        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<n;i++){
            if (intervals[i][0]<=end){
                end=max(end,intervals[i][1]);
            }
            else
            {
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> mergedIntervals = sol.merge(intervals);
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    return 0;
};