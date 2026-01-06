#include <map>
#include <set>
#include <vector>
#include <queue>
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
    vector<TreeNode*>ans;

    // TreeNode* helper(TreeNode* root,set<int>& st){
    //     if(!root) return root;
    //     root->left=helper(root->left,st);
    //     root->right=helper(root->right,st);
    //     if(st.find(root->val)!=st.end()){
    //         if(root->left)ans.push_back(root->left);
    //         if(root->right) ans.push_back(root->right);
    //         return NULL;
    //     }
    //     return root;
    // }



    void mark_parents(TreeNode* root , map<TreeNode* , TreeNode*>& mp){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto x=q.front();
                q.pop();
                if (x->left){
                    mp[x->left]=x;
                    q.push(x->left);
                }
                if (x->right){
                    mp[x->right]=x;
                    q.push(x->right);
                }
            }
        }
    }

    void helper(TreeNode* root , set<int>& st , map<TreeNode*,TreeNode*>& mp){
        if(!root) return;
        helper(root->left,st,mp);
        helper(root->right,st,mp);
        if (st.count(root->val)){
            TreeNode* parent=mp[root];
            if (root->left) ans.push_back(root->left);
            if (root->right) ans.push_back(root->right);
        
            if(parent){
                if(parent->left==root)parent->left=NULL;
                else parent->right=NULL;
            }
        }
    }


    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        set<int>st(to_delete.begin(),to_delete.end());
        map<TreeNode*,TreeNode*>mp;
        mark_parents(root,mp);
        helper(root,st,mp);
        if(!st.count(root->val)){
            ans.push_back(root);
        }


        // optimised method without parent pointer 

        
        // TreeNode* remaining_forest = helper(root,st);
        // if(remaining_forest)
        // ans.push_back(remaining_forest);

        return ans;


    }
};