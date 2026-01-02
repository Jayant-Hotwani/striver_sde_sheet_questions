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
    TreeNode* build(vector<int>& preorder,int pre_start,int pre_end,vector<int>& postorder,
                    int post_start, int post_end , map<int,int>& mp){
        
        if(pre_start>pre_end || post_start>post_end) return NULL;

        int root_val=preorder[pre_start];
        TreeNode* root= new TreeNode(root_val);
        if (pre_start == pre_end) return root;
        int left_root=preorder[pre_start+1];
        int index=mp[left_root]; 
        int left_size=index-post_start+1;

        root->left=build(preorder,pre_start+1,pre_start+left_size,postorder,post_start,index,mp);
        root->right=build(preorder,pre_start+1+left_size,pre_end,postorder,index+1,post_end-1,mp);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        int n=postorder.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[postorder[i]]=i;
        }
        return build(preorder,0,n-1,postorder,0,n-1,mp);
    }
};