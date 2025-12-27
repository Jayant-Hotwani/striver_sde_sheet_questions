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

 class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string s="";
        if(!root) return s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto x=q.front();
                q.pop();
                if (x==NULL){
                    s+="#";
                    s+=",";
                }
                else{
                    s+=to_string(x->val);
                    s+=",";
                }

                if(x!=NULL){
                    q.push(x->left);
                    q.push(x->right);
                }
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size()==0) return 0;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* x=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#"){
                x->left=NULL;
            }
            else{
                TreeNode* leftNode=new TreeNode(stoi(str));
                x->left=leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str=="#"){
                x->right=NULL;
            }
            else{
                TreeNode* rightNode=new TreeNode(stoi(str));
                x->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));