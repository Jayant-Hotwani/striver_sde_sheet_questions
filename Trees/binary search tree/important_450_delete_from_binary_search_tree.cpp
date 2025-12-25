#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* left_most_node_of_right_subtree(TreeNode* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root)return root;
        
        if (root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else if (root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{
            // we have found target
            if(root->left==NULL) return root->right;
            else if(root->right==NULL) return root->left;
            else{
                TreeNode* rightSubtree=root->right;
                TreeNode* left_subtree=root->left;
                // detach leftsubtree and append to leftmost of right;
                TreeNode* leftmost_of_right=left_most_node_of_right_subtree(root->right);
                leftmost_of_right->left=left_subtree;

                return rightSubtree;
            }
        }
        return root;
    }
};