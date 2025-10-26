/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};  
// Time Complexity: O(m+n)
// Space Complexity: O(1)
// Intersection of two linked lists
// Approach:
// 1. Using hash set to store nodes of first list and then checking nodes of second list
// 2. Calculating lengths of both lists and aligning them to find intersection
// 3. Two pointer technique to traverse both lists and find intersection without extra space        
// Note: If the two linked lists have no intersection at all, return null.


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // unordered_set< ListNode*>s;
        // while (headA!=NULL)
        // {
        //     s.insert(headA);
        //     headA=headA->next;
        // }
        //  while (headB!=NULL)
        // {
        //      if (s.find(headB)!=s.end())
        //          return headB;
           
        //     headB=headB->next;
        // }
        // return nullptr;


        //better solution without extra space; time complexity - > o(m+n)+o(m-n) = (2m)
        // int len1=0;
        // int len2=0;
        // ListNode* temp1=headA;
        // ListNode* temp2=headB;
        // while(temp1!=NULL){
        //     len1++;
        //     temp1=temp1->next;
        // }
        // while(temp2!=NULL){
        //     len2++;
        //     temp2=temp2->next;
        // }
        // temp1=headA;
        // temp2=headB;
        // if (len1>len2){
        //     int d=len1-len2;
        //     for(int i=0;i<d;i++){
        //         temp1=temp1->next;
        //     }
        // }
        // else{
        //     int d=len2-len1;
        //     for(int i=0;i<d;i++){
        //         temp2=temp2->next;
        //     }
        // }

        // while(temp1!=NULL || temp2!=NULL)
        // {
        //     if (temp1==temp2) return temp1;
        //     temp1=temp1->next;
        //     temp2=temp2->next;
        // }

        // return NULL;


        // best optimal solution 

        ListNode* dummy1=headA;
        ListNode* dummy2=headB;

        while(dummy1!=dummy2){
            if (dummy2==NULL) dummy2=headA;
            else
            dummy2=dummy2->next;
            
            if (dummy1==NULL) dummy1=headB;
            else
            dummy1=dummy1->next;
            
        }
        return dummy1;
      
    }
};

int main() {
    Solution sol;
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);

    ListNode* headB = new ListNode(4);
    headB->next = new ListNode(5);
    headB->next->next = headA->next;  // Create intersection at node with value 2

    ListNode* intersection = sol.getIntersectionNode(headA, headB);
    if (intersection) {
        std::cout << "Intersection at node with value: " << intersection->val << std::endl;
    } else {
        std::cout << "No intersection found." << std::endl;
    }

    return 0;
}