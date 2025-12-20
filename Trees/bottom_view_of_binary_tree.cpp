

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        map<int,int>mp;
        // for each horizontal line we will store only last level node's value
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto x=q.front();
                q.pop();
                Node* node=x.first;
                int hd=x.second;
                mp[hd]=node->data;
                if (node->left!=NULL){
                    q.push({node->left,hd-1});
                }
                if (node->right!=NULL){
                    q.push({node->right,hd+1});
                }
            }
        }
        
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};

int main() {
    return 0;
}