#include <bits/stdc++.h>
using namespace std;

    
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }

};

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        map<int,int>mp;
        // for every level we will be storing only 1st element we see
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto x=q.front();
                q.pop();
                Node* node=x.first;
                int level=x.second;
                if(mp.find(level)==mp.end())
                mp[level]=node->data;
                
                if (node->left!=NULL)
                q.push({node->left,level+1});
                
                if(node->right!=NULL)
                q.push({node->right,level+1});
            }
        }
        vector<int>ans;
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};