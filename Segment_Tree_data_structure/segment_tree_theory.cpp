// Segment Tree — full implementation
// -----------------------------------
// Supports, all in O(log n):
//   - build(arr)                 O(n)
//   - updatePoint(idx, val)      set arr[idx] = val
//   - updateRange(l, r, val)     add val to every element in arr[l..r] (lazy propagation)
//   - queryRange(l, r)           sum of arr[l..r]
//
// Internally the tree is stored as a flat array (like a binary heap):
// node 1 is the root, node i's children are 2*i and 2*i+1.
// Size 4*n is a safe upper bound on the number of nodes needed for n leaves.
//
// To adapt this to range-min / range-max / range-gcd instead of range-sum,
// change three things (marked with "ADAPT:" comments below):
//   1. the merge operation in build() and the update/query merge steps
//   2. the "identity" value returned for no-overlap in query_range()
//   3. the lazy push_down() formula IF you switch to range-min/max
//      (min/max updates use a different lazy formula than sum — see note below)



// query sum 


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> segmentTree;

    void buildSegmentTree(int arr[], int node, int l, int r) {
        if (l == r) {
            segmentTree[node] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegmentTree(arr, 2 * node + 1, l, mid);
        buildSegmentTree(arr, 2 * node + 2, mid + 1, r);

        segmentTree[node] =
            segmentTree[2 * node + 1] +
            segmentTree[2 * node + 2];
    }

    int querysum(int start, int end, int node, int l, int r) {

        // No overlap
        if (start > r || end < l)
            return 0;

        // Complete overlap
        if (start <= l && r <= end)
            return segmentTree[node];

        int mid = l + (r - l) / 2;

        return querysum(start, end, 2 * node + 1, l, mid)
             + querysum(start, end, 2 * node + 2, mid + 1, r);
    }

    vector<int> querySum(int n, int arr[], int q, int queries[]) {

        segmentTree.resize(4 * n);

        buildSegmentTree(arr, 0, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < q; i += 2) {
            int start = queries[i];
            int end = queries[i + 1];

            ans.push_back(
                querysum(start, end, 0, 0, n - 1)
            );
        }

        return ans;
    }
};


//. query minimum among queries 

class Solution {
  public:
  
    vector<int>segmentTree;
    void buildSegmentTree(int node , vector<int>& arr , int l , int r){
        if(l==r){
            segmentTree[node]=arr[l];
            return;
        }
        int mid=l+(r-l)/2;
        buildSegmentTree(2*node+1 , arr , l , mid);
        buildSegmentTree(2*node+2 , arr , mid+1 , r);
        segmentTree[node]=min(segmentTree[2*node+1],segmentTree[2*node+2]);
    }
    int query_minimum(int start , int end , int node , int l , int r){
        if (end<l || start>r) return 1e9;
        if (l>=start && r<=end) return segmentTree[node];
        int mid=l+(r-l)/2;
        return min(query_minimum(start,end,2*node+1,l,mid)
                    ,query_minimum(start,end,2*node+2,mid+1,r));
    }
    vector<int> rangeMinQuery(vector<int>& arr, vector<vector<int>>& q) {
        // code here
        int n = arr.size();
        segmentTree.resize(4*n);
        
        buildSegmentTree(0,arr,0,n-1);
        vector<int>ans;
        for(int i=0;i<q.size();i++){
            int start=q[i][0];
            int end=q[i][1];
            ans.push_back(query_minimum(start,end,0,0,n-1));
        }
        return ans;
        
    }
};


// 