
#include <bits/stdc++.h>
using namespace std;

struct Node {
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
    vector<int> preOrder(Node* root) {
        // code here
        
        // lets find all order traversal in one traversal
        stack<pair<Node*,int>>st;
        vector<int>preOrder,postOrder,inOrder;
        st.push({root,1});
        while(!st.empty()){
            auto& x=st.top();
            int val=x.second;
            Node* node=x.first;
            if (val==1){
                preOrder.push_back(node->data);
                st.top().second++;
                if(node->left!=NULL){
                    st.push({node->left,1});
                }
            }else if (val==2){
                inOrder.push_back(node->data);
                st.top().second++;
                if(node->right!=NULL){
                    st.push({node->right,1});
                }
            }else{
                postOrder.push_back(node->data);
                st.pop();
            }
        }
        return preOrder;   
    }
};

int main() {
    return 0;
}