#include <bits/stdc++.h>
using namespace std;

// Function to get the maximum value in Knapsack
// val[]: values of items
// wt[]: weights of items
// cap: capacity of knapsack
// Returns the maximum value that can be put in knapsack
// Link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-158
class Solution {
  public:

  // Function to get the maximum value in Knapsack
  // intuition: sort items by value/weight ratio in descending order
  // then take as much as possible from the highest ratio item until capacity is full
  // TC: O(nlogn) SC: O(n)
  
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int cap) {
        // code here
        vector<pair<double,double>>v;
        int n=wt.size();
        for(int i=0;i<n;i++){
            double x=(1.00*(val[i]))/wt[i];
            v.push_back({x,(double)wt[i]});
        }
        double ans=0;
        sort(v.rbegin(),v.rend());
        for(int i=0;i<v.size() && cap>0 ;i++){
            double x=v[i].first;
            if (cap>=v[i].second){
                cap-=v[i].second;
                ans+=double(x*(v[i].second));
            }
            else{
                ans+=double(x*(cap));
                break;
            }
        }
        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50; // Example capacity
    double maxValue = solution.fractionalKnapsack(values, weights, capacity);
    std::cout << "Maximum value in Knapsack = " << maxValue << std::endl;
    return 0;
}