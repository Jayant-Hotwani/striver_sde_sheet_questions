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
    vector<int>res;
    int index=0;
    bool helper(TreeNode* root,vector<int>& voyage){
        if(!root) return true;

        if(root->val != voyage[index])
        return false;

        index++;
        if (root->left && index<voyage.size() && root->left->val !=voyage[index]){
            if (root->right && root->right->val==voyage[index]){
                res.push_back(root->val);
                swap(root->left,root->right);
            }
            else{
                return false;
            }
        }

        return helper(root->left ,voyage) && helper(root->right,voyage);
    }


    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (helper(root,voyage)==false)return {-1};
        return res;
    }
};