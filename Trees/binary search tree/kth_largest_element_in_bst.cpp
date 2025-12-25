#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        data = data;
        left = right = NULL;
    }
};
// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    
    void inorder_count(Node* root, int& total){
        if(!root) return;
        inorder_count(root->left,total);
        total++;
        inorder_count(root->right,total);
    }
    
    void inorder(Node* root, int& ans , int& k){
        if(!root) return;
        inorder(root->left,ans,k);
        k--;
        if(k==0){
            ans=root->data;
            return ;
        }
        inorder(root->right,ans,k);
    }
    int kthLargest(Node *root, int k) {
        // Your code here
        int total=0;
        inorder_count(root,total);
        // cout<<"total"<<total<<endl;
        int smallest=total-k+1;
        // cout<<smallest<<endl;
        
        int ans=-1;
        inorder(root,ans,smallest);
        return ans;
        
        
    }
};