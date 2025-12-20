#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    bool isSumProperty(Node *root) {
        if(!root) return true;
        // code here
        if(root->left==NULL && root->right==NULL) return true;
        int left=0;
        int right=0;
        
        if(root->left!=NULL)
        left=root->left->data;
        if (root->right!=NULL)
        right=root->right->data;
        
        if (left+right!=root->data) return false;
        
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};