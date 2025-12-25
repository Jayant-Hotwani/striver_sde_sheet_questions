#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution {
  public:
    int floor(Node* root, int x) {
        // code here
        
        if (!root) return -1;
        int floor=-1e9;
        while(root){
            if(root->data==x){
                return x;
            }
            else if (root->data>x){
                root=root->left;
            }
            else{
                floor=root->data;
                root=root->right;
            }
        }
        if (floor==-1e9) return -1;
        return floor;
    }
};