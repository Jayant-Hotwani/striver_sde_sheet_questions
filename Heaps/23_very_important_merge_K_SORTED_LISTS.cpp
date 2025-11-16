
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:

    ListNode* merge_two_sorted_list(ListNode* head1,ListNode* head2)
    {
        
        ListNode* l1=head1;
        ListNode* l2=head2;
        
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        if(l1->val>l2->val){
            ListNode* temp=l1;
            l1=l2;
            l2=temp;
        }
        ListNode* anshead=l1;
        while(l1!=NULL && l2!=NULL){
            if(l1->val>l2->val){
            ListNode* temp=l1;
            l1=l2;
            l2=temp;
        }
            ListNode* prev;
            while(l1!=NULL && l1->val<=l2->val){
                prev=l1;
                l1=l1->next;
            }
            prev->next=l2;
        }
        return anshead;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        // ListNode* ans=lists[0];
        // for(int i=1;i<lists.size();i++){
        //     ans=merge_two_sorted_list(ans,lists[i]);
        // }
        // return ans;


        // using min priority_queue
        priority_queue<pair<int,ListNode*>,
        vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;

        for(int i=0;i<lists.size();i++){
            ListNode* head=lists[i];
            if(head!=NULL)
            pq.push({head->val,head});
        }

        ListNode* ans =new ListNode(-1);
        ListNode* curr=ans;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();

            ListNode* nextnode=new ListNode(x.first);
            curr->next=nextnode;
            curr=curr->next;
            
            ListNode* temp=x.second;
            if (temp->next!=NULL)
            pq.push({temp->next->val,temp->next});
        }
        return ans->next; 
    }
};

int main(){
    return 0;
}