#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  // Function to return k maximum sum combinations from two arrays.
  // TC: O(k log k) SC: O(k)
  // Approach: Sort both arrays in descending order. Use a max-heap to store the maximum sum combinations.
  // Start with the largest elements from both arrays. Use a set to track visited index pairs
  // to avoid duplicates. Extract the maximum sum from the heap, add it to the result,
  // and push the next possible combinations into the heap until we have k sums.
  // This ensures we efficiently get the top k sums without generating all combinations.
  // Reference: https://www.geeksforgeeks.org/k-maximum-sum-combinations-two-arrays/
  // https://www.youtube.com/watch?v=1g0hG8zz5mA
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