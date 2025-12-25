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

    void mark_parents(TreeNode* root,map<TreeNode*,TreeNode*>& parents){
        parents[root]=NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto x=q.front();
                q.pop();

                if (x->left!=NULL){
                    parents[x->left]=x;
                    q.push(x->left);
                }
                if (x->right!=NULL){
                    parents[x->right]=x;
                    q.push(x->right);
                }
            }
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // normal lca
        // if (root==NULL || root==p || root==q)
        // return root;

        // TreeNode* left=lowestCommonAncestor(root->left,p,q);
        // TreeNode* right=lowestCommonAncestor(root->right,p,q);

        // if (left==NULL) return right;
        // else if (right==NULL) return left;
        // else{
        //     return root;
        // }

        // method 2 for normal lca mark parent pointers traverse node1->root , store in set 
        // trverse node2->root,find in set

        // map<TreeNode*,TreeNode*>parents;
        // mark_parents(root,parents);

        // set<TreeNode*>st;
        // while(p!=NULL){
        //     st.insert(p);
        //     p=parents[p];
        // }

        // while(st.find(q)==st.end()){
        //     q=parents[q];
        // }

        // return q;


        // most optimised method for only binary search tree ..
        //  simple find node where p lies on left and q lies on right 
        // o(log2n) o(hieght of bst)
        if(!root) return NULL;

        while(1){
            if(p->val > root->val && q->val>root->val){
                root=root->right;
            }
            else if (p->val < root->val && q->val<root->val){
                root=root->left;
            }
            else{
                return root;
            }
        }

        


    }
};