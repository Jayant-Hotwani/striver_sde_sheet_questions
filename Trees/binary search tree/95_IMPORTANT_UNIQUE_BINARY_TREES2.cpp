#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> helper(int start , int end){
        if (start>end)return {NULL};
        if (start==end){
            return {new TreeNode(start)};
        }
        vector<TreeNode*> res;

        for(int i=start;i<=end;i++){
            vector<TreeNode*> left_bst=helper(start,i-1);
            vector<TreeNode*> right_bst=helper(i+1,end);
            
            for(auto x:left_bst){
                for(auto y:right_bst){
                    TreeNode* root=new TreeNode(i);
                    root->left=x;
                    root->right=y;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {

        return helper(1,n);
        
    }
};