#include<bits/stdc++.h>
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
    // void inorder(TreeNode* root,vector<int>& v){
    //     if(!root)return;
    //     inorder(root->left,v);
    //     v.push_back(root->val);
    //     inorder(root->right,v);
    // }

    void inorder_map(TreeNode* root,map<int,int>& mp , bool& ans , int k ){
        if(!root)return ;
        inorder_map(root->left,mp,ans,k);
        if (mp.find(k-(root->val))!=mp.end()){
            ans=true;
            return ;
        }
        mp[root->val]++;
        inorder_map(root->right,mp,ans,k);
    }


    bool findTarget(TreeNode* root, int k) {
        // naive solution do inorder and perform 2 sum 
        // vector<int>v;
        // inorder(root,v);

        // int n=v.size();
        // int i=0;
        // int j=n-1;
        // while(i<j){
        //     int sum=v[i]+v[j];
        //     if (sum==k)return true;
        //     else{
        //         if (sum>k)j--;
        //         else i++;
        //     }
        // }
        // return false;



        // one more method using maps 

        map<int,int>mp;
        bool ans=false;
        inorder_map(root,mp,ans,k);
        return ans;

    }
};