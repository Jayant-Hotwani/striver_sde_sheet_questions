#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define ll long long
class Node {
    public:
    bool isBst=true;
    ll sum=0;
    ll mini;
    ll maxi;
    Node(bool isBst , ll sum , ll maxi , ll mini){
        this->isBst=isBst;
        this->sum=sum;
        this->maxi=maxi;
        this->mini=mini;
    }
 };

class Solution {
public:
    // bool validate(TreeNode* root , int mini , int maxi){
    //     if(!root) return true;
    //     if (root->val <= mini || root->val>= maxi) return false;
    //     return validate(root->left,mini,root->val) && validate(root->right,root->val,maxi);

    // }
    // bool validateBST(TreeNode* root){
    //     int mini=-1e9;
    //     int maxi=1e9;
    //     return validate(root,mini,maxi);
    // }
    // int ans=0;

    // int calc_sum(TreeNode* root){
    //     int ans=0;
    //     if(root==NULL) return 0;
    //     return root->val+calc_sum(root->left)+calc_sum(root->right);
    // }

    ll ans=0;
    Node* helper(TreeNode* root){
        if(!root) return new Node(true,0,INT_MIN,INT_MAX);

        Node* left=helper(root->left);
        Node* right=helper(root->right);

        ll left_maxi=left->maxi;
        ll right_mini=right->mini;

        if (root->val > left_maxi && root->val < right_mini && left->isBst && right->isBst){
            ll new_sum=left->sum+right->sum+root->val;
            ans=max(ans,new_sum);
            ll new_mini=min((ll)root->val,left->mini);
            ll new_maxi=max((ll)root->val,right->maxi);
            return new Node(true,new_sum,new_maxi,new_mini);
        }
        return new Node(false,max({(ll)0,left->sum,right->sum}),INT_MAX,INT_MIN);
    }


    int maxSumBST(TreeNode* root) {
        // if (root == NULL) return 0;

        // if (validateBST(root)) {
        //     ans = max(ans, calc_sum(root));
        // }

        // maxSumBST(root->left);
        // maxSumBST(root->right);

        // return ans;

        // optimal 
        helper(root);
        return ans;


    }
};