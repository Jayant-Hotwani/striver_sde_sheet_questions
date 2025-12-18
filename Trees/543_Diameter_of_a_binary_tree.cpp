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
    // Helper function to compute the height of the tree and update the diameter
    // simultaneously.
    // Height is defined as the number of edges on the longest path from the node to a leaf.
    // This function updates the diameter (ans) by considering the sum of the heights
    // of the left and right subtrees at each node.
    
    int hieght(TreeNode* root, int& ans){
        if(root==NULL) return 0;
        int lh=hieght(root->left,ans);
        int rh=hieght(root->right,ans);
        ans=max(ans,lh+rh);
        return 1+max(rh,lh);

    }
    // Function to compute the diameter of the binary tree
    // The diameter is defined as the length of the longest path between any two nodes in the tree.
    // This path may or may not pass through the root.
    // The length of a path is represented by the number of edges between the nodes.
    // Time Complexity: O(N), where N is the number of nodes in the tree.
    // Space Complexity: O(H), where H is the height of the tree (due to recursion stack).
    // Auxiliary Space: O(1)

    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        hieght(root,ans);
        return ans;
    }
};
int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << sol.diameterOfBinaryTree(root) << endl;  // Output: 3
    return 0;
}