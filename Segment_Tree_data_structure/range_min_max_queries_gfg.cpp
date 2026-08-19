#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    vector<int>getMinMaxUtil(int start , int end , int node , int l , int r,
                             vector<vector<int>>& segTree){
       
       if(l>end || r<start) return {INT_MAX,INT_MIN};
       if(l>=start && r<=end )return segTree[node];
       
       int mid=l+(r-l)/2;
       vector<int> left=getMinMaxUtil(start,end,2*node+1,l,mid,segTree);
       vector<int> right=getMinMaxUtil(start,end,2*node+2,mid+1,r,segTree);
       return {min(left[0],right[0]),max(left[1],right[1])};
    }
    
    vector<int> getMinMax(vector<int>& arr, int L, int R,
                          vector<vector<int>>& segTree) {
                              
       int n=arr.size();
       return getMinMaxUtil(L,R,0,0,n-1,segTree);
        
    }
    
    void updateSegmentTree(int index , int value , int node, int l , int r ,
                            vector<vector<int>>& segTree )
    {
        if(l==r){
            segTree[node][0]=value;
            segTree[node][1]=value;
            return ;
        }
        
        int mid=l+(r-l)/2;
        if(index<=mid)
        updateSegmentTree(index,value,2*node+1,l,mid,segTree);
        else
        updateSegmentTree(index,value,2*node+2,mid+1,r,segTree);
        
        segTree[node][0]=min(segTree[2*node+1][0],segTree[2*node+2][0]);
        segTree[node][1]=max(segTree[2*node+1][1],segTree[2*node+2][1]);
        
    }
    
    
    void updateValue(vector<int>& arr, int index, int value,
                     vector<vector<int>>& segTree) {
                         
        int n=arr.size();
        arr[index]=value;
        updateSegmentTree(index,value,0,0,n-1,segTree);
    }
    
};