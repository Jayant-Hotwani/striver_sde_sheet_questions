#include <bits/stdc++.h>
using namespace std;

vector<int>segmentTree;
vector<int>lazySegmentTree;

// lets build segment tree

void build(int node , int l , int r , vector<int>& arr){
    if(l==r){
        segmentTree[node]=arr[l];
        return ;
    }
    int mid=l+(r-l)/2;
    build(2*node+1,l,mid,arr);
    build(2*node+2,mid+1,r,arr);
    segmentTree[node]=segmentTree[2*node+1]+segmentTree[2*node+2];
}

// push down lazily the value to children 

void push_down(int node , int l ,int r){
    if(lazySegmentTree[node]==0)return ;

    segmentTree[node]+=(r-l+1)*lazySegmentTree[node];

    if(l!=r){
        // not a leaf node
        lazySegmentTree[2*node+1]+=lazySegmentTree[node];
        lazySegmentTree[2*node+2]+=lazySegmentTree[node];
    }
    lazySegmentTree[node]=0;
}

void rangeUpdate(int node , int l , int r , int start , int end , int val ){

    push_down(node,l,r);
    
    if (l>end || r<start)return ;
    if(l>=start && r<=end){
        segmentTree[node]+=(r-l+1)*val;
        if(l!=r){
            lazySegmentTree[2*node+1]+=val;
            lazySegmentTree[2*node+2]+=val;
        }
        return ;
    }
    int mid=l+(r-l)/2;
    rangeUpdate(2*node+1,l,mid,start,end,val);
    rangeUpdate(2*node+2,mid+1,r,start,end,val);
    segmentTree[node]=segmentTree[2*node+1]+segmentTree[2*node+2];
}

int rangeQuery(int node , int l , int r , int start , int end){
    push_down(node,l,r);

    if (l>end || r<start)return 0 ;

    if(l>=start && r<=end) return segmentTree[node];

    int mid=l+(r-l)/2;
    int leftSum=rangeQuery(2*node+1,l,mid,start,end);
    int rightSum=rangeQuery(2*node+2,mid+1,r,start,end);
    return leftSum+rightSum;
}


int main(){
   
    vector<int> arr = {1, 2, 3, 4,5,6,7,8,9,8,7,6,3,3,2};

    int n = arr.size();

    segmentTree.resize(4*n);
    lazySegmentTree.assign(4*n, 0);

    build(0, 0, n-1, arr);

    // Initial sum = 10
    cout << rangeQuery(0, 0, n-1, 0, 3) << endl;

    // Add 10 to [1,3]
    // [1,2,3,4] -> [1,12,13,14]
    rangeUpdate(0, 0, n-1, 1, 3, 10);

    // Sum = 40
    cout << rangeQuery(0, 0, n-1, 0, 3) << endl;

    // Sum [1,2] = 12 + 13 = 25
    cout << rangeQuery(0, 0, n-1, 1, 2) << endl;

    // Add 5 to [0,2]
    // [1,12,13,14] -> [6,17,18,14]
    rangeUpdate(0, 0, n-1, 0, 2, 5);

    // Sum = 55
    cout << rangeQuery(0, 0, n-1, 0, 3) << endl;

    return 0;

}
