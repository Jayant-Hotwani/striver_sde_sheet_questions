#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    ListNode* next;
    int val;
    ListNode(int x){
        val=x;
    }
};

class queue_impl{
    public:
    ListNode* start=NULL;
    ListNode* end=NULL;

    void push(int x)
    {
        ListNode* temp=new ListNode(x);
        if(start==NULL && end==NULL){
            start=temp;
            end=temp;
        }
        else{
            end->next=temp;
            end=end->next;
        }
    }

    void pop(){
        if(start==NULL && end==NULL) return;
        if (start==end){
            ListNode* rem=start;
            delete(rem);
            start=NULL;
            end=NULL;
        }
        else{
            ListNode* rem=start;
            start=start->next;
            delete(rem);
        }
        
    }

    int top(){
        if(start!=NULL) return start->val;
        else return -1;
    }

};

int main(){
    queue_impl q;
    q.push(1);
    q.push(2);
    q.push(4);
    q.pop();
    cout<<q.top()<<endl;


}