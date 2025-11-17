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

class stack_impl{
    public:
    ListNode* head=NULL;

    void push(int x){
        ListNode* new_node=new ListNode(x);
        new_node->next=head;
        head=new_node;
    }

    void pop(){
        ListNode* temp=head;
        if (head!=NULL)
        head=head->next;
        else
        return;
    }
    
    int top(){
        if(head!=NULL)
        return head->val;
        else return -1;
    }


};


int main(){
    stack_impl st;
    st.push(1);
    st.push(2);
    st.pop();
    st.push(3);
    st.pop();
    cout<<st.top()<<"--"<<endl;

}