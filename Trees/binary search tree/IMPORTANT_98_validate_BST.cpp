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
    void inOrder(TreeNode* root,vector<int>& inorder){
        if(!root)return;
        inOrder(root->left,inorder);
        inorder.push_back(root->val);
        inOrder(root->right,inorder);
    }

    bool is_sorted(vector<int>& inorder){
        for(int i=0;i<inorder.size()-1;i++){
            if (inorder[i]>=inorder[i+1])return false;
        }
        return true;
    }


    bool isValid(TreeNode* root, long long mini , long long  maxi){
        if (!root) return true;
        if (root->val<=mini || root->val>=maxi) return false;
        return isValid(root->left,mini,root->val) 
            && isValid(root->right,root->val,maxi); 
    }



    bool isValidBST(TreeNode* root) {

        // naive basic method ... 

        vector<int>inorder;
        inOrder(root,inorder);
        // return is_sorted(inorder);


        // for each node maintain min/max range values 
        if(!root)return true;

        long long  mini=-1e12;
        long long  maxi=1e12;

        return isValid(root,mini,maxi);



    }
};