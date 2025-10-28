/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;   
        }
        return prev;
    }

    ListNode* rotateRightByOnePlace(ListNode* head){
        if (head==NULL) return NULL;
        ListNode* secondLast=NULL;
        ListNode* start=head;
        ListNode* last=NULL;
        while(head->next!=NULL){
            secondLast=head;
            head=head->next;
        }
        last=head;
        secondLast->next=NULL;
        last->next=start;
        return last;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        // brute force approach
        if (k==0) return head;
        if (head==NULL) return NULL;
        if (head->next==NULL) return head;
        // int n=0;
        // ListNode* temp=head;
        // while(temp!=NULL){
        //     n++;
        //     temp=temp->next;
        // }
        // k=k%n;
        // if (k==0) return head;

        // ListNode* ans=NULL; 
        // for(int i=0;i<k;i++){
        //     ListNode* ans=rotateRightByOnePlace(head);
        //     head=ans;
        // }
        // return head;

        // most optimal approach 

        // if (k==0) return head;
        // if (head==NULL) return NULL;
        // if (head->next==NULL) return head;
        // // reverse whole linked list first
        // // then reverse 1st k group then reverse remainig elements
        // int n=0;
        // ListNode* temp=head;
        // while(temp!=NULL){
        //     n++;
        //     temp=temp->next;
        // }
        // k=k%n;
        // if (k==0) return head;

        // head=reverse(head);

        // // reverse first k;
        // ListNode* curr=head;
        // ListNode* prev=NULL;
        // while(curr!=NULL && k>0){
        //     ListNode* next=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=next;
        //     k--;
        // }
        // // rverse remaining
        // head->next=reverse(curr);
        // return prev;
        

        // one more very easy optimal approach 

        int count=0;
        ListNode* temp=head;
        ListNode* last=NULL;
        while(temp!=NULL){
            count++;
            last=temp;
            temp=temp->next;
        }
        k=k%count;
        // connect last node to head;
        last->next=head;
        // skip count -k -1 links 
        ListNode* prev=NULL;
        for(int i=0;i<count-k;i++) {
            prev=head;
            head=head->next;
        }
        // break link
        prev->next=NULL;
        return head;
    }
};

int main() {
    // Example usage:
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    ListNode* rotatedHead = sol.rotateRight(head, k);

    // Print rotated list
    ListNode* temp = rotatedHead;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}