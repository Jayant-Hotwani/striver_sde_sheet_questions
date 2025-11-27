#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    void insert_into_correct_position(stack<int>& st , int val){
        if (st.empty() || val>=st.top()){
            st.push(val);
        }
        else{
            int x=st.top();
            st.pop();
            insert_into_correct_position(st,val);
            st.push(x);
        }
    }
    void sortStack(stack<int> &st) {
        // code here
        if (st.empty())return;
        
        // lets do it recusively
        // assume rec func gives u sorted stack
        // enter this element accordinly 
        
        int x=st.top();
        st.pop();
        sortStack(st);
        
        // after recursion ends 
        // stack<int>temp;
        // while(!st.empty()&&st.top()>x){
        //     temp.push(st.top());
        //     st.pop();
        // }
        // st.push(x);
        // while(!temp.empty()){
        //     st.push(temp.top());
        //     temp.pop();
        // }
        
        // we can do this without extra auxillary space too 
        
        insert_into_correct_position(st,x);
    }
};
