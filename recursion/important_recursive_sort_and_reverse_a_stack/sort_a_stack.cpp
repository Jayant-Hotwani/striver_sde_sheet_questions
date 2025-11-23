#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    void insert_correct_position(stack<int>& st , int val){
        if (st.empty() || val>=st.top()){
            st.push(val);
        }
        else{
            int x=st.top();
            st.pop();
            insert_correct_position(st,val);
            st.push(x);
        }
    } 
  
    void sortStack(stack<int> &st) {
        // code here
        if (st.size()==0) return ;
        int x=st.top();
        st.pop();
        sortStack(st);
        insert_correct_position(st,x);
    }
};
