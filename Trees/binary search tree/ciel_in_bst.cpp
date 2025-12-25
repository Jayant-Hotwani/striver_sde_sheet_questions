#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
    
class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        if(!root) return -1;
        int ans=-1;
        while(1){
            if(root==NULL) return ans;
            if (root->data==x) return x;
            else if (root->data>x){
                ans=root->data;
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
        
        return ans;
    }
};
