#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int>segmentTree;
    void buildSegmentTree(int node , int l , int r , vector<int>&arr){
        
        if(l==r){
            segmentTree[node]=arr[l];
            return ;
        }
        int mid=l+(r-l)/2;
        buildSegmentTree(2*node+1,l,mid,arr);
        buildSegmentTree(2*node+2,mid+1,r,arr);
        segmentTree[node]=segmentTree[2*node +1 ]+segmentTree[2*node+2];
    }
    
    int querySum(int start , int end , int node , int l , int r){
        if(start>r || end<l)return 0;
        if(l>=start && r<=end) return segmentTree[node];
        int mid=l+(r-l)/2;
        return querySum(start,end,2*node+1,l,mid)+querySum(start,end,2*node+2,mid+1,r);
    }
    
    void update (int index , int node , int val , int l , int r){
        if(l==r){
            segmentTree[node]=val;
            return ;
        }
        int mid=l+(r-l)/2;
        if(index<=mid)
        update(index , 2*node+1,val,l,mid);
        else
        update(index, 2*node+2,val,mid+1,r);
        
        segmentTree[node]=segmentTree[2*node +1 ]+segmentTree[2*node+2];
    }
    
    vector<int> rangeSumQueries(vector<int>& arr, 
    vector<vector<int>>& q) {
        // code here
        int n=arr.size();
        segmentTree.resize(4*n);
        buildSegmentTree(0,0,n-1,arr);
        
        vector<int>ans;
        for(int i=0;i<q.size();i++){
            if(q[i][0]==1){
                int start=q[i][1];
                int end=q[i][2];
                ans.push_back(querySum(start,end,0,0,n-1));
            }else{
                int index=q[i][1];
                int val=q[i][2];
                update(index, 0 , val , 0 , n-1);
            }
        }
        return ans;
        
        
    }
};
int main(){
    return 0;
}