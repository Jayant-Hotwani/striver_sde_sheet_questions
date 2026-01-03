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

class CBTInserter {
public:
    TreeNode* ans;
    
    queue<TreeNode*>q;
    CBTInserter(TreeNode* root) {
        ans=root;
        // queue<TreeNode*>temp;
        // temp.push(root);
        // while(!temp.empty()){
        //     auto x=temp.front();
        //     temp.pop();
        //     if(x->left==NULL || x->right==NULL){
        //         q.push(x);
        //     }
        //     if(x->left)temp.push(x->left);
        //     if(x->right)temp.push(x->right);
        // }
    }
    
    int insert(int val) {

        // old naive sol
        TreeNode* node=new TreeNode(val);
        queue<TreeNode*>q;
        q.push(ans);
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            if(x->left && x->right){
                q.push(x->left);
                q.push(x->right);
                continue;
            }

            if (x->left==NULL){
                x->left=node;
                return x->val;
            }
            if (x->right==NULL){
                x->right=node;
                return x->val;
            }
            
        }

        return 0;
        // TreeNode* node=new TreeNode(val);
        // auto x=q.front();
        // if(x->left==NULL){
        //     x->left=node;
        //     q.push(x->left);
        // }
        // else{
        //     x->right=node;
        //     q.push(x->right);
        //     q.pop();
        // }
        // return x->val;

    }
    
    TreeNode* get_root() {
        return ans;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */