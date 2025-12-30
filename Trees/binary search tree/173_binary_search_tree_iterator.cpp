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

class BSTIterator {
public:
    // vector<int>in;
    // int index;
    // void inorder(TreeNode* root, vector<int>& in){
    //     if(!root)return;
    //     inorder(root->left,in);
    //     in.push_back(root->val);
    //     inorder(root->right,in);
    // }

    // basically we are doing same thing but without storing / recursion or extra traversal in array
    // push left most 
    // pick top of stack 
    // check if right is present,  move to left most part

    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        // inorder(root,in);
        // index=0;

        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        // int val=in[index];
        // index++;
        // return val;

        auto x=st.top();
        st.pop();
        if(x->right){
            TreeNode* curr=x->right;
            while(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
        }
        return x->val;
    }
    
    bool hasNext() {
        // return index<in.size();
        return st.size()>0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */