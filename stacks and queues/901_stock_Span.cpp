#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    // stack<int>q;
    // stack<int>st;
    int index=-1;
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        // int ans=1;
        // while(!st.empty() && st.top()<=price){
        //     q.push(st.top());
        //     st.pop();
        //     ans++;
        // }
        // while(!q.empty()){
        //     st.push(q.top());
        //     q.pop();
        // }
        // st.push(price);
        // return ans;  

        // we can do this using single stack also
        index+=1;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }

        int ans=index-(st.empty()?-1:st.top().second);
        st.push({price,index});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
