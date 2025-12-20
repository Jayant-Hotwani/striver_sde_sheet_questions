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
#include <cmath>
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

        // o(n^2) solution

    int height(TreeNode* root){
        if(!root)return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int lh=height(root->left);
        int rh=height(root->right);
        if (abs(lh-rh)>1)return false;

        return isBalanced(root->left)&&isBalanced(root->right);
    }



     // o(n) solution
        int height(TreeNode* root){
            if(!root) return 0;
            int lh=height(root->left);
            int rh=height(root->right);
            if (lh==-1 || rh==-1) return -1;
            if (abs(lh-rh)>1) return -1;
            return 1+max(lh,rh);

        }
        bool isBalanced(TreeNode* root){
            return height(root)!=-1;
        }

};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    cout << sol.isBalanced(root) << endl;  // Output: 1 (true)
    return 0;
}