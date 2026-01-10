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
    // int ans=0;
    // optimized method -

    // vector<int> helper(TreeNode* root , int distance){
    //     if(!root) return {};
    //     if (root->left ==NULL && root->right==NULL) return {1};

    //     vector<int>left=helper(root->left,distance);
    //     vector<int>right=helper(root->right,distance);
    //     for(auto x:left){
    //         for(auto y:right){
    //             if(x+y<=distance){
    //                 ans++;
    //             }
    //         }
    //     }

    //     vector<int>res;
    //     for(auto x:left){
    //         if(x+1<distance) res.push_back(x+1);
    //     }
    //     for(auto x:right){
    //         if(x+1<distance) res.push_back(x+1);
    //     }
    //     return res;
    // }

    void mark_parents(TreeNode* root , map<TreeNode* , TreeNode*>& parent){
        queue<TreeNode*>q;
        q.push(root);
        parent[root]=NULL;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto x=q.front();
                q.pop();

                if(x->left){
                    parent[x->left]=x;
                    q.push(x->left);
                }
                if(x->right){
                    parent[x->right]=x;
                    q.push(x->right);
                }
            }
        }
    }

    void mark_leaf(TreeNode* root,set<TreeNode*>& leafs){
        if(!root)return ;
        if (root->left==NULL && root->right==NULL){
            leafs.insert(root);
        }
        mark_leaf(root->left,leafs);
        mark_leaf(root->right,leafs);
    }

    int countPairs(TreeNode* root, int distance) {

        // optomized method - 
        // helper(root,distance);
        // return ans;

        // brute method -
        //  find all leaf nodes put into set , run bfs on all leaf nodes 

        map<TreeNode*,TreeNode*>parent;
        mark_parents(root,parent);

        set<TreeNode*>leafs;
        mark_leaf(root,leafs);
        int ans=0;
        for(auto leaf:leafs){
            set<TreeNode*>vis;
            vis.insert(leaf);
            queue<TreeNode*>q;
            q.push(leaf);
            int level=0;
            while(!q.empty() && level<=distance){
                int sz=q.size();
                while(sz--){
                    auto x=q.front();
                    q.pop();

                    if (x!=leaf && x->left==NULL && x->right==NULL){
                        ans++;
                        continue;
                    }

                    TreeNode* par=parent[x];
                    TreeNode* left=x->left;
                    TreeNode* right=x->right;

                    if(par!=NULL && !vis.count(par)){
                        vis.insert(par);
                        q.push(par);
                    }
                    if(left!=NULL && !vis.count(left)){
                        vis.insert(left);
                        q.push(left);
                    }
                    if (right!=NULL && !vis.count(right)){
                        vis.insert(right);
                        q.push(right);
                    }
                }
                if (q.size()>0)
                level++;
            }
        }
        // cout<<ans<<endl;
        return ans/2;
    }
};