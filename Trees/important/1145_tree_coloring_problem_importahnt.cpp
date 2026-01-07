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

    int left_subtree=0;
    int right_subtree=0;

    int helper(TreeNode* root , int x){
        if (!root) return 0;

        int left=helper(root->left,x);
        int right=helper(root->right,x);

        if (root->val==x){
            left_subtree=left;
            right_subtree=right;
        }
        return 1+left+right;
    }


    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int total=n;
        int win=n/2;
        helper(root,x);
        
        int parent=n-(left_subtree+right_subtree+1);
        int maxiii=max({parent,left_subtree,right_subtree});
        return maxiii>win;
    }
};