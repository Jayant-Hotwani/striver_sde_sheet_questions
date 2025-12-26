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

    void inorder(TreeNode* root , vector<int>& ans){
        if (!root)return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {

        // vector<int>ans;
        // inorder(root,ans);
        // return ans;


        // lets try iterative in order 

        // vector<int>inorder;
        // TreeNode* node=root;
        // stack<TreeNode*> st;
        // while(true){
        //     if(node!=NULL){
        //         st.push(node);
        //         node=node->left;
        //     }
        //     else{
        //         if(st.empty())break;
        //         node=st.top();
        //         st.pop();
        //         inorder.push_back(node->val);
        //         node=node->right;
        //     }
        // }
        // return inorder;

        // morris traversal tough - i dont like this shit 

        vector<int>ans;
        if(!root) return ans;
        TreeNode* curr=root;
        while(curr!=NULL){
            if (curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }else{
                TreeNode* prev=curr->left;
                // keep moving right of left subtree
                while(prev->right!=NULL && prev->right!=curr){
                    prev=prev->right;
                }
                // if no thread found , make thread and move right
                if (prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    // if thread found , means left covered , break thread move right
                    prev->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
        
    }
};