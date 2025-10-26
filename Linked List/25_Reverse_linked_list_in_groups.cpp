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
    // damn important question

    ListNode* reverseKGroup(ListNode* head, int k) {

        int count=0;
        ListNode* temp =head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }

        if (count-k<0) return head;

        // reverse first group 
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;
        int cnt=0;
        // reverse first k pairs 
        while(curr!=NULL && cnt<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        // continue process for next remaining list 
        if (next!=NULL){
            ListNode* remainingHead=reverseKGroup(next,k);
            head->next=remainingHead;
        }
        return prev; 
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 2;

    ListNode* newHead = sol.reverseKGroup(head, k);
    while (newHead != NULL) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    return 0;
}