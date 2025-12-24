#include<bits/stdc++.h>
using namespace std;

class TreeNode {
  public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a new node
    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};
// 222. Count Complete Tree Nodes
// https://leetcode.com/problems/count-complete-tree-nodes/
// Difficulty: Medium
// Given the root of a complete binary tree, return the number of the nodes in the tree.
// According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree,
// and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
// Design an algorithm that runs in less than O(n) time complexity.
// Example 1:
// Input: root = [1,2,3,4,5,6]
// Output: 6
// Example 2:
// Input: root = []
// Output: 0
// Example 3:
// Input: root = [1]
// Output: 1
// Constraints:
// The number of nodes in the tree is in the range [0, 5 * 10^4].
// 0 <= Node.val <= 5 * 10^4    
    // TC: O(logn * logn)
    // SC: O(1)

class Solution {
public:

    int left_height(TreeNode* root){
        if (!root) return 0;
        int ans=0;
        while(root!=NULL){
            ans++;
            root=root->left;
        }
        return ans;   
    }

    int right_height(TreeNode* root){
        if (!root) return 0;
        int ans=0;
        while(root!=NULL){
            ans++;
            root=root->right;
        }
        return ans;
        
    }

    int helper(TreeNode* root){
        if(!root) return 0;
        int lh=left_height(root);
        int rh=right_height(root);
        if (lh==rh){
            return pow(2,rh)-1;
        }
        return 1+helper(root->left)+helper(root->right);
    }

    int countNodes(TreeNode* root) {
        
        if(!root) return 0;
        // basic naive solution can be any of traversal techniques 
        // pre/post/in/level order traversal - tc O(n);

        return helper(root);
        
    }
};