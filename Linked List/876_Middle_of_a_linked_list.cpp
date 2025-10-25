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
// Find middle of linked list
// Two Approaches:
// 1. Using slow and fast pointer
// 2. Counting number of nodes and then traversing to middle    

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // best optimal approach
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next !=nullptr ){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;

        // int count=0;
        // ListNode* temp=head;
        // while(temp!=NULL){
        //     count++;
        //     temp=temp->next;
        // }
        // int mid=count/2;
        // while(mid>0){
        //     mid--;
        //     head=head->next;
        // }
        // return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* middleHead = solution.middleNode(head);

    // Print middle list
    ListNode* curr = middleHead;
    while (curr != NULL) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;

    return 0;
}
