#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    
    void insert_correct_pos(stack<int>& st , int val){
        if (st.empty()) 
        st.push(val);
        else{
            int x=st.top();
            st.pop();
            insert_correct_pos(st,val);
            st.push(x);
        }
        return;
    }
    void reverseStack(stack<int> &st) {
        // code here
        
        // will recursively call reverse stack until stack is empty 
        // then will insert element ony by one (from start rec call)
        
        if (st.empty()) return;
        int x=st.top();
        st.pop();
        reverseStack(st);
        // insert_correct_pos(st,x);

        // approach 2
        // or we can do using extra space also
        stack<int>temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
};