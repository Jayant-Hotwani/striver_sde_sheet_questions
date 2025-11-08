#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
     static bool mycmp(pair<int,int>& a , pair<int,int>& b){
        if (a.second==b.second)
        return a.first<b.first;

        return a.second<b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
            int n=start.size();
            vector<pair<int,int>>v;
            for(int i=0;i<n;i++){
                v.push_back({start[i],end[i]});
            }

            sort(v.begin(),v.end(),mycmp);
            int ans=1;
            int end_time=v[0].second;
            for(int i=1;i<n;i++){
                if (v[i].first>end_time){
                    ans++;
                    end_time=v[i].second;
                }
            }
            return ans;
        
    }
};

int main() {
    Solution solution;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    int maxMeetings = solution.maxMeetings(start, end);
    std::cout << "Max meetings in one room: " << maxMeetings << std::endl;
    return 0;
}