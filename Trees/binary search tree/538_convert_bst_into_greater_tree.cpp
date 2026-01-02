#include<bits/stdc++.h>
using namespace std;
class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  
};  

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& in){
        if(!root) return ;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    void set_inorder(TreeNode* root,int& index, vector<int>& in){
        if(!root) return ;
        set_inorder(root->left,index,in);
        root->val=in[index];
        index++;
        set_inorder(root->right,index,in);
    }

    int sum=0;
    TreeNode* convertBST(TreeNode* root) {

        // naive approach

        // vector<int>in;
        // inorder(root,in);
        // int n=in.size();
        // for(int i=n-2;i>=0;i--){
        //     in[i]+=in[i+1];
        // }
        // int index=0;
        // set_inorder(root,index,in);
        // return root;
            // ---------------------------------------- // 

        // start from right then root then left computing sum;

        // optimal approach
        if(!root) return root;

        convertBST(root->right);
        sum+=root->val;
        root->val=sum;
        convertBST(root->left);

        return root;

    }
};