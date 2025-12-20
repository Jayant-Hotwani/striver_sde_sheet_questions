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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;

        // hd , level , set 
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto x=q.front();
                q.pop();
                TreeNode* node=x.first;
                int hd=x.second.first;
                int level=x.second.second;

                mp[hd][level].insert(node->val);
                if (node->left!=NULL){
                    q.push({node->left,{hd-1,level+1}});
                }
                if (node->right!=NULL){
                    q.push({node->right,{hd+1,level+1}});
                }
            }
        }


        for(auto x:mp){
            int hd=x.first;
            vector<int>v;
            map<int,multiset<int>>& mpp=x.second;
            for(auto y:mpp){
                int level=y.first;
                multiset<int>& st=y.second;
                for(auto z:st){
                    v.push_back(z);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};

int main(){
    return 0;
}