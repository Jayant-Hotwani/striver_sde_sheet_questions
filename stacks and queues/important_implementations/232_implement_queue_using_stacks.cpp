#include <bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    // whenever we have push operation perform 3 steps 
    // step 1 - take out evrything from st1 and put in st2
    // step 2- push new element in stack 1
    // step 3 -> push all elements from stack 2 back to stack 1;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int x = st1.top();
        st1.pop();
        return x;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

 int main(){
    return 0;
 }