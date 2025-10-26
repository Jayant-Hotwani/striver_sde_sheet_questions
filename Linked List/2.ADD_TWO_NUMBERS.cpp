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
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};  
// Time Complexity: O(max(m,n))
// Space Complexity: O(max(m,n))
// Add two numbers represented by linked lists
// Note: The digits are stored in reverse order, and each of their nodes contain a single digit.
// We need to add the two numbers and return it as a linked list.
// We can simulate the addition process digit by digit, taking care of the carry for sums greater than 9.
// 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry=0;
        ListNode* dummy =new ListNode(0);
        ListNode* temp=dummy;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if (l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if (l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=0;
            if (sum>9){
                sum=sum%10;
                carry=1;
            }
            ListNode* newnode=new ListNode(sum);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;   
    }
};

int main(){
    Solution sol;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = sol.addTwoNumbers(l1, l2);
    while (result != NULL) {
        std::cout << result->val << " ";
        result = result->next;
    }
    return 0;   
}