/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};  


class Solution {
  public:
  
    Node* merge(Node* root1,Node* root2){
        
        Node* temp=new Node(0);
        Node* res=temp;
        
        while(root1!=NULL && root2!=NULL){
            if (root1->data<root2->data){
                temp->bottom=root1;
                root1=root1->bottom;
                temp=temp->bottom;
            }
            else{
                temp->bottom=root2;
                root2=root2->bottom;
                temp=temp->bottom;
            }
        }
        
        if (root1) temp->bottom=root1;
        else {
            temp->bottom=root2;
        }
    
        return res->bottom;
    }
    Node *flatten(Node *root) {
        // vector<int>v;
        // while(root!=NULL){
        //   Node* temp=root;
        //   v.push_back(temp->data);
        //   if(temp->bottom){
        //       temp=temp->bottom;
        //       while(temp->bottom!=NULL){
        //           v.push_back(temp->data);
        //           temp=temp->bottom;
        //       }
        //       v.push_back(temp->data);
        //   }
        //   root=root->next;
        // }
        // sort(v.begin(),v.end());
        // Node* head=new Node(0);
        // Node* curr=head;
        // for(int i=0;i<v.size();i++){
        //     Node* temp=new Node(v[i]);
        //     temp->next=NULL;
        //     curr->bottom=temp;
        //     curr=curr->bottom;
        // }
        // return head->bottom;
        
        // better solution without extra space 
        // merge two sroted linked list in bottom manner
        // do recursion 
        // first merge last two then ...recursively 
        
        if (root==NULL || root->next==NULL) return root;
        Node* sorted_next=flatten(root->next);
        Node* rooted=merge(sorted_next,root);
        
        return rooted;
    }
};

int main() {
    Solution sol;
    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);
    head->bottom = new Node(7);
    head->bottom->next = new Node(8);
    head->bottom->next->next = new Node(30);
    head->next->bottom = new Node(20);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->next = new Node(35);
    head->next->next->next->bottom = new Node(40);
    head->next->next->next->bottom->next = new Node(45);
    Node* flattened = sol.flatten(head);
    while (flattened != NULL) {
        cout << flattened->data << " ";
        flattened = flattened->bottom;
    }
    return 0;
}