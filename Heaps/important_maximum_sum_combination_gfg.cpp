#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        vector<int>ans;
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({a[0]+b[0],{0,0}});
        set<pair<int,int>>st;
        st.insert({0,0});
        while(!pq.empty() && ans.size()<k){
            auto x=pq.top();pq.pop();
            int sum=x.first;
            int i=x.second.first;
            int j=x.second.second;
            ans.push_back(sum);
            if (st.find({i+1,j})==st.end()){
                int new_sum=a[i+1]+b[j];
                pq.push({new_sum,{i+1,j}});
                st.insert({i+1,j});
            }
            if (st.find({i,j+1})==st.end()){
                int new_sum=a[i]+b[j+1];
                st.insert({i,j+1});
                pq.push({new_sum,{i,j+1}});
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> a={2,3,6,7,9};
    vector<int> b={1,4,8,10};
    int k=5;
    vector<int> result = sol.topKSumPairs(a, b, k);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}