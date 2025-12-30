#include<bits/stdc++.h>
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
    bool validate(TreeNode* root , int mini , int maxi){
        if(!root) return true;
        if (root->val <= mini || root->val>= maxi) return false;
        return validate(root->left,mini,root->val) && validate(root->right,root->val,maxi);

    }
    bool validateBST(TreeNode* root){
        int mini=-1e9;
        int maxi=1e9;
        return validate(root,mini,maxi);
    }
    int ans=0;

    int calc_sum(TreeNode* root){
        int ans=0;
        if(root==NULL) return 0;
        return root->val+calc_sum(root->left)+calc_sum(root->right);
    }
    int maxSumBST(TreeNode* root) {

        //most naive approach
        // we will check for every subtree if its a bst or not if yes we will calculate its sum and update the ans
        // tc:O(n^2)
        
         if (root == NULL) return 0;

        if (validateBST(root)) {
            ans = max(ans, calc_sum(root));
        }

        maxSumBST(root->left);
        maxSumBST(root->right);

        return ans;
    }
};