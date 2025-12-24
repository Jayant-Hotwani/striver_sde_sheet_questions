#include <vector>
#include <stack>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int data) {
        data = data;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
  
    void traverse_left(Node* root,vector<int>& v){
        if (!root)return ;
        if (root->left==NULL && root->right==NULL) return;
        if(root->left!=NULL){
            v.push_back(root->data);
            traverse_left(root->left,v);
        }
        else{
            v.push_back(root->data);
            traverse_left(root->right,v);
        }
    }
    stack<int>st;
    void traverse_right(Node* root,vector<int>& v){
        if (!root)return ;
        if (root->left==NULL && root->right==NULL) return;
        if(root->right!=NULL){
            st.push(root->data);
            traverse_right(root->right,v);
        }
        else{
            st.push(root->data);
            traverse_right(root->left,v);
        }
        
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
    }
    void traverse_leaf(Node* root,vector<int>& v){
        if (!root) return;
        if (root->left==NULL && root->right==NULL) {
            v.push_back(root->data);
            return;
        }
        traverse_leaf(root->left,v);
        traverse_leaf(root->right,v);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        
        vector<int>v;
        if (!root) return v;
        v.push_back(root->data);
        if(root -> left == NULL && root -> right == NULL)
        return v;
        traverse_left(root->left,v);
        traverse_leaf(root,v);
        traverse_right(root->right,v);
        
        return v;
        
    }
};