#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    
    void helper(Node* root, vector<int>& ds , vector<vector<int>>& ans){
        if(root->left==NULL && root->right==NULL){
            ds.push_back(root->data);
            ans.push_back(ds);
            ds.pop_back();
            return;
        }
        
        ds.push_back(root->data);
        if (root->left!=NULL){
            helper(root->left,ds,ans);
        }
        if (root->right!=NULL){
            helper(root->right,ds,ans);
        }
        ds.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        
        vector<vector<int>>ans;
        vector<int>ds;
        helper(root,ds,ans);
        return ans;
        
    }
};