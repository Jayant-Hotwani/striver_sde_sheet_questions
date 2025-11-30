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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if (!root) return ans;

        int level=0;
        queue<TreeNode*>q;

        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int>v;
            // cout<<level<<endl;
            while(sz--){
                auto x=q.front();
                q.pop();
                v.push_back(x->val);
                if (x->left) q.push(x->left);
                if (x->right) q.push(x->right);
            }
            if (v.size()>0){
                if (level%2==0){
                    ans.push_back(v);
                }
                else{
                    reverse(v.begin(),v.end());
                    ans.push_back(v);
                }
            }
            level++;
        }
        return ans;
    }
};