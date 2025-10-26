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
#include <string>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// Time Complexity: O(n)
// Space Complexity: O(1)
// Palindrome Linked List
// Approach:
// 1. Convert linked list to string and check if string is palindrome
// 2. Find middle of linked list, reverse second half and compare with first half
// Note: A linked list is a palindrome if the sequence of values is the same forwards and backwards.

class Solution {
public:

    ListNode* reverse(ListNode* head){

        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    };

    bool isPalindrome(ListNode* head) {
        // naive o(2*N)
        string s="";

        while(head!=NULL){
            s+=to_string(head->val);
            head=head->next;
        }

        int n=s.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;

        // without extra space
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        // reverse remaining half 
        ListNode* reverseHead=reverse(slow->next);
        while(reverseHead!=NULL && head!=NULL){
            if (reverseHead->val!=head->val) return false;
            reverseHead=reverseHead->next;
            head=head->next;
        }
        return true;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    bool result = sol.isPalindrome(head);
    if (result) {
        std::cout << "The linked list is a palindrome." << std::endl;
    } else {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }
    return 0;
}