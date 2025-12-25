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
    void inOrder(TreeNode* root, int& ans , int& k){
        if(!root)return;
        inOrder(root->left,ans,k);
        k--;
        if (k==0){
            ans=root->val;
            return;
        }
        inOrder(root->right,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        // naive - write inorder and return inorder[k-1];
        int ans=-1;
        inOrder(root,ans,k);
        return ans;
    }
};