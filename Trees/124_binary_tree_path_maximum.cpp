/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include <algorithm>
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

    int height(TreeNode* root,int& ans){
        if(!root) return 0;
        int left=height(root->left,ans);
        left=max(0,left);
        int right=height(root->right,ans);
        right=max(0,right);
        ans=max(ans,(left+right+root->val));
        return (root->val + max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans=-1e9;
        height(root,ans);
        return ans;  
    }
};

int main(){
    return 0;
}