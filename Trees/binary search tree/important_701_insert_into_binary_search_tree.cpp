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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* old_root=root;
        TreeNode* temp=new TreeNode(val);
        if(!root) return temp;
        while(1){
            if(root->val>val){
                if (root->left!=NULL)
                    root=root->left;
                else{
                    root->left=temp;
                    return old_root;
                }
            }
            else{
                    if(root->right!=NULL){
                        root=root->right;
                    }
                    else{
                        root->right=temp;
                        return old_root;
                    }
            }
            
        }
        return old_root;

    }
};