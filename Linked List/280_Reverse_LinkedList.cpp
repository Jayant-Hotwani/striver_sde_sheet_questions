
#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Iterative approach to reverse a linked list
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    // Print reversed list
    ListNode* curr = reversedHead;
    while (curr != NULL) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;

    return 0;
}