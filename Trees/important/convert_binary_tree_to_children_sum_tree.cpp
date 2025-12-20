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
    void makeChildrenSum(TreeNode* root) {
        if (!root) return;

        int childSum = 0;

        if (root->left)
            childSum += root->left->val;
        if (root->right)
            childSum += root->right->val;

        // Top-down adjustment
        if (childSum > root->val) {
            root->val = childSum;
        } else {
            if (root->left)
                root->left->val = root->val;
            if (root->right)
                root->right->val = root->val;
        }

        // Recurse
        makeChildrenSum(root->left);
        makeChildrenSum(root->right);

        // Bottom-up adjustment
        int total = 0;
        if (root->left)
            total += root->left->val;
        if (root->right)
            total += root->right->val;

        if (root->left || root->right)
            root->val = total;
    }
};

int main() {
    return 0;
}