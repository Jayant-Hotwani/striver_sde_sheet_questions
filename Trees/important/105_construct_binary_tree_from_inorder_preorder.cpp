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

    TreeNode* helper(vector<int>& inorder , int in_start , int in_end,
                     vector<int>& preorder, int pre_start , int pre_end,
                     map<int,int>& mp){

        
        if(in_start>in_end || pre_start>pre_end) return NULL;

        int root_val=preorder[pre_start];
        int index=mp[root_val];
        int leftSize = index - in_start;
        TreeNode* root=new TreeNode(root_val);
    root->left=helper(inorder,in_start,index-1,preorder,pre_start+1,pre_start+leftSize,mp);
    root->right=helper(inorder,index+1,in_end,preorder,pre_start+leftSize+1,pre_end,mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        TreeNode* root=NULL;
        if (preorder.empty() || inorder.empty()) return NULL;
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        // int find=preorder[0];
        // root=new TreeNode(find);
        // int index=mp[find];
        // vector<int>new_inorder_left(inorder.begin(),inorder.begin()+index);
        // vector<int>new_preorder_left(preorder.begin()+1,preorder.begin()+index+1);
        // root->left=buildTree(new_preorder_left,new_inorder_left);
        // vector<int>new_inorder_right(inorder.begin()+index+1,inorder.end());
        // vector<int>new_preorder_right(preorder.begin()+index+1,preorder.end());
        // root->right=buildTree(new_preorder_right,new_inorder_right);

        // return root;


        // better way space efficuent

        return helper(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,mp);

    }
};