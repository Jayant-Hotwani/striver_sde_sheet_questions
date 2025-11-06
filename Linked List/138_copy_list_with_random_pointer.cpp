#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {

        // most basic naive with extra space 
        // map<Node* ,Node*> mp;
        // Node* temp=head;
        // while(temp!=NULL){
        //     Node* dummy = new Node(temp->val);
        //     mp[temp]=dummy;
        //     temp=temp->next;
        // }

        // temp=head;
        // while(temp!=NULL){
        //     Node* copy=mp[temp];
        //     copy->next=mp[temp->next];
        //     copy->random=mp[temp->random];
        //     temp=temp->next;
        // }
        // temp=head;
        // return mp[temp];


        // better approach with no extra space container

        // step 1 create a dummy node after each node 
        // if (head==NULL) return NULL;
        // Node* temp=head;
        // while(temp!=NULL){
        //     Node* nextNode = temp->next;
        //     Node* dummy = new Node(temp->val);
        //     temp->next = dummy;
        //     dummy->next = nextNode;
        //     temp = nextNode;
        // }
        // temp=head;
        // appoint random pointer to each dummy node 
        // dummy->random = temp->random->next
        // while(temp!=NULL){
        //     Node* actualRandomNext=temp->random;
        //     Node* dummy =temp->next;
        //     if (actualRandomNext==NULL){
        //         dummy->random=NULL;
        //     }
        //     else
        //     dummy->random=(actualRandomNext)->next;

        //     temp=(temp->next)->next;
        // }

        //     Node* orig = head;
        //     Node* copy = head->next;
        //     Node* copyHead = copy;

        //     while (orig != NULL && copy != NULL) {
        //         orig->next = copy->next;
        //         orig = orig->next;
        //         if (orig != NULL)
        //             copy->next = orig->next;
        //         copy = copy->next;
        //     }

        //     return copyHead;


            // practice it once again
            // step 1 create a dummy node after each node

            if (head==NULL) return NULL;
            Node* temp =head;
            while(temp!=NULL){
                Node* nextNode=temp->next;
                Node* dummy= new Node(temp->val);
                temp->next=dummy;
                dummy->next=nextNode;
                temp=nextNode;
            }

            // step2 assign random pointers
            temp=head;
            while(temp!=NULL){
                Node* actualRandomNext=temp->random;
                Node* dummynext=temp->next;
                if (actualRandomNext==NULL){
                    dummynext->random=NULL;
                }
                else
                dummynext->random=actualRandomNext->next;
                temp=dummynext->next;
            }

            Node* orig=head;
            Node* copy =head->next;
            Node* copyHead=copy;

            while(orig!=NULL && copy!=NULL){
                Node* realNext=copy->next;
                orig->next=realNext;
                orig=orig->next;
                if (orig!=NULL){
                    Node* copyNext=orig->next;
                    copy->next=copyNext;
                }
                copy=copy->next;
            }
            
            return copyHead;

    }
};

int main() {
    // Example usage:
    Solution solution;
    // Create a linked list with random pointers and test the function
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next->next;  // 1's random points to 3
    head->next->random = head;        // 2's random points to 1
    head->next->next->random = head->next; // 3's random points to 2

    Node* copiedList = solution.copyRandomList(head);

    // Print the original and copied lists
    Node* temp = head;
    cout << "Original list:" << endl;
    while (temp != NULL) {
        cout << "Value: " << temp->val;
        if (temp->random != NULL) {
            cout << ", Random: " << temp->random->val;
        }
        cout << endl;
        temp = temp->next;
    }

    temp = copiedList;
    cout << "Copied list:" << endl;
    while (temp != NULL) {
        cout << "Value: " << temp->val;
        if (temp->random != NULL) {
            cout << ", Random: " << temp->random->val;
        }
        cout << endl;
        temp = temp->next;
    }

    return 0;
}