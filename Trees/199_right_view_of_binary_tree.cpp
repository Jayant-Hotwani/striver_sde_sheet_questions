/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
    vector<int> rightSideView(TreeNode* root) {

        if(!root) return {};
        map<int,int>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto x=q.front();
                q.pop();
                int level=x.second;
                TreeNode* node=x.first;
                mp[level]=node->val;

                if (node->left!=NULL)
                q.push({node->left,level+1});
                if (node->right!=NULL)
                q.push({node->right,level+1});
            }
        }
        vector<int>ans;
        for(auto x:mp){
            ans.push_back(x.second);
        }

        return ans;
        
    }
};

int main() {
    return 0;
}