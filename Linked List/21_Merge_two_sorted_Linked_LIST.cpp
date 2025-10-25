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

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
#include <iostream>
#include <vector>
using namespace std; 

// Time Complexity: O(n+m)
// Space Complexity: O(1)
// Merge two sorted linked list
// Two Approaches:
// 1. Using arrays to store values and then merging arrays and creating linked list
// 2. Proper linked list merging without using extra space for arrays


class Solution {
public:

    vector<int> mergeTwoSortedArrays(vector<int>& v1 , vector<int>& v2){
        int i=0;
        int j=0;
        vector<int>temp;
        while(i<v1.size() && j<v2.size()){
            if (v1[i]<=v2[j]){
                temp.push_back(v1[i]);
                i++;
            }
            else{
                temp.push_back(v2[j]);
                j++;
            }
        }

        while(i<v1.size()){
            temp.push_back(v1[i]);
            i++;
        }
        while(j<v2.size()){
            temp.push_back(v2[j]);
            j++;
        }
        return temp;
    }

    ListNode* MergeTwoSortedLinkedList(ListNode* list1, ListNode* list2){

        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        while(list1!=NULL && list2!=NULL){
            if (list1->val<=list2->val){
                ListNode* newNode=new ListNode(list1->val);
                temp->next = newNode;
                temp=temp->next;
                list1=list1->next;
            }
            else{
                ListNode* newNode=new ListNode(list2->val);
                temp->next = newNode;
                temp=temp->next;
                list2=list2->next;
            }
        }

        while(list1!=NULL){
            ListNode* newNode=new ListNode(list1->val);
            temp->next = newNode;
            temp=temp->next;
            list1=list1->next;
        }
        while(list2!=NULL){
            ListNode* newNode=new ListNode(list2->val);
            temp->next = newNode;
            temp=temp->next;
            list2=list2->next;
        }

        return head->next;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // vector<int>v1;
        // vector<int>v2;
        // while(list1!=NULL){
        //     v1.push_back(list1->val);
        //     list1=list1->next;
        // }
        // while(list2!=NULL){
        //     v2.push_back(list2->val);
        //     list2=list2->next;
        // }
        // vector<int>v3=mergeTwoSortedArrays(v1,v2);
        // ListNode* head= new ListNode(0);
        // ListNode* temp=head;
        // for(int i=0;i<v3.size();i++){
        //     ListNode* listnode=new ListNode(v3[i]);
        //     temp->next=listnode;
        //     temp=temp->next;
        // }
        // return head->next;

        // proper linked list approach 

         // uses extra space for new linked list 
        // return MergeTwoSortedLinkedList(list1,list2);

        // best optimal 
        // no extra space O(1) time complexity O(n+m)
        // changing pointers only

        ListNode* l1=list1;
        ListNode* l2=list2;

        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if (l1->val > l2->val){
            ListNode* temp=l1;
            l1=l2;
            l2=temp;
        }

        ListNode* res=l1;
        while(l1!=NULL && l2!=NULL){
            ListNode* prev=NULL;
            while(l1!=NULL && l1->val <= l2->val){
                prev=l1;
                l1=l1->next;
            }
            prev->next=l2;

            ListNode* temp=l1;
            l1=l2;
            l2=temp;
        }

        return res;
        
    }
};

int main() {
    // Example usage:
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Print merged list
    ListNode* curr = mergedList;
    while (curr != NULL) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;

    return 0;
}