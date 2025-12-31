#include <bits/stdc++.h>
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
    // void inorder(TreeNode* root,vector<int>& v){
    //     if(!root) return;
    //     inorder(root->left,v);
    //     v.push_back(root->val);
    //     inorder(root->right,v);
    // }
    // void correct_inorder(TreeNode* root,int& index , vector<int>& v){
    //     if(!root) return;
    //     correct_inorder(root->left,index,v);
    //     root->val=v[index];
    //     index++;
    //     correct_inorder(root->right,index,v);
    // }


    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;


    void optimized_inorder(TreeNode* root){
        
        if(!root)return ;
        optimized_inorder(root->left);

        if(prev!=NULL){
            if(prev->val>root->val){
                if(first==NULL){
                first=prev;
                middle=root;
                }
                else{
                    last=root;
                }
            }
        }

        prev=root;

        optimized_inorder(root->right);
    }


    void recoverTree(TreeNode* root) {
        // vector<int>v;
        // inorder(root,v);
        // sort(v.begin(),v.end());
        // int index=0;
        // correct_inorder(root,index,v);

        first=NULL;
        middle=NULL;
        last=NULL;
        prev=NULL;

        optimized_inorder(root);

        if(first && last) swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);
    }
};