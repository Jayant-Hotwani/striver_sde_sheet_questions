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
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// Time Complexity: O(n)
// Space Complexity: O(1)
// Remove Nth Node from end of linked list
// Two Approaches:
// 1. Counting number of nodes and then removing the (count-n)th node
// 2. Using slow and fast pointer to find the nth node from end in one pass 
//   and remove it 
// Note: Using a dummy node to handle edge cases like removing the head node



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {


        // this approach is o(2n)
        // int count=0;
        
        // ListNode* temp=head;
        // while(temp!=NULL){
        //     count++;
        //     temp=temp->next;
        // }
        // // if there is only one node return null
        // if(count==1) return NULL;

        // temp=head;
        // int skip_node_from_start=count-n;

        // // important .. it means remove first node 
        // if(skip_node_from_start==0)
        // return head->next;
       
        // for(int i=0;i<skip_node_from_start-1;i++){
        //     head=head->next;
        // }
        
        // ListNode* t=head->next->next;
        // head->next=t;
        // return temp;

        // O(n) approach using slow and fast pointer;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        
        for(int i=1;i<=n;i++){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return dummy->next;

    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    int n = 2; // Example: Remove the 2nd node from the end
    ListNode* modifiedHead = solution.removeNthFromEnd(head, n);

    // Print modified list
    ListNode* curr = modifiedHead;
    while (curr != NULL) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;

    return 0;
}   