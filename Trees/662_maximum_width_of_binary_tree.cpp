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
    int widthOfBinaryTree(TreeNode* root) {
       
       int ans=0;
       queue<pair<TreeNode*,long long >>q;
       q.push({root,0});
       while(!q.empty()){
        int first,last;
        int sz=q.size();
        long long  min=q.front().second;
        for(int i=0;i<sz;i++){
            long long  curr=q.front().second-min;
            TreeNode* node=q.front().first;
            q.pop();
            if (i==0) first=curr;
            if(i==sz-1) last=curr;
            if (node->left!=NULL) q.push({node->left,(long long)(2*curr)+1});
            if (node->right!=NULL) q.push({node->right,(2*curr)+2});
        }
        ans=max(ans,(last-first+1));
       }
       return ans;
    }
};

int main() {
    return 0;
}