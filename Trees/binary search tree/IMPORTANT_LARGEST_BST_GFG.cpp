#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};


class TreeNode{
    public:
    int size ;
    int maxi;
    int mini;
    TreeNode(int size , int maxi , int mini){
        this->size=size;
        this->maxi=maxi;
        this->mini=mini;
    }
};

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    TreeNode* helper(Node* root){
        
        if(!root) return new TreeNode(0,INT_MIN,INT_MAX);
        
        auto left=helper(root->left);
        auto right=helper(root->right);
        
        if(root->data > left->maxi && root->data < right->mini){
            int new_size=left->size+right->size+1;
            int new_mini=min(root->data,left->mini);
            int new_maxi=max(root->data,right->maxi);
            return new TreeNode(new_size,new_maxi,new_mini);
        }
        
        return new TreeNode(max(left->size,right->size),INT_MAX,INT_MIN);
    }
    
    int largestBst(Node *root) {
        
        // Your code here
        return helper(root)->size;
        
    }
};