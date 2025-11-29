#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    bool ispal(string& s , int i , int j){
        
        while(i<=j){
            if (s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
   
    
    
    int minChar(string &s) {
        // code here
        int ans=0;
        int n=s.size();
        while(ispal(s,0,n-1)==false){
            ans++;
            s.pop_back();
        }
        return ans;
        
        // better optimization can be kmp
        
       
        
    }
};
