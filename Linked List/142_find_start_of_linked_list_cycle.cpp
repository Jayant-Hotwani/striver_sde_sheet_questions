/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// Time Complexity: O(n)
// Space Complexity: O(1)
// Find the start of the cycle in linked list
// Approach: Using Floyd's Cycle Detection Algorithm (Tortoise and Hare Algorithm)
// Note: Once a cycle is detected, reset one pointer to the head and move both pointers
// one step at a time; the point where they meet is the start of the cycle.     

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        if (head==NULL || head->next==NULL) return NULL;
        while(true){
            if(fast==NULL || fast->next==NULL) return NULL;
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast)break;
        }

        fast=head;
        while(fast!=slow){
            slow=slow->next;
            fast=fast->next;
        }
        return (slow);
        
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Create a cycle

    ListNode* cycleStart = sol.detectCycle(head);
    if (cycleStart) {
        std::cout << "Cycle starts at node with value: " << cycleStart->val << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    return 0;
}   