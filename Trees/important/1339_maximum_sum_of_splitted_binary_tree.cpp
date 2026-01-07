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
    #define ll long long 
    ll dfs_sum(TreeNode* root){
        if(!root)return 0;
        return root->val+dfs_sum(root->left)+dfs_sum(root->right);
    }

    ll helper(TreeNode* root , ll& total , ll& ans){
        if(!root)
        return 0;

        ll left=helper(root->left,total,ans);
        ll right=helper(root->right,total,ans);
        ll curr_sum=root->val+left+right;
        ll rem=total-curr_sum;
        ans=max(ans,(curr_sum*rem));
        return curr_sum;
    }


    int maxProduct(TreeNode* root) {
        ll total_sum=dfs_sum(root);
        ll ans=0;
        ll mod=1e9+7;
        helper(root,total_sum,ans);
        return ans%mod;
    }
};