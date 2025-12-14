#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> search(string &pat, string &text) {
        // code here
        int m = pat.size();
        int n = text.size();
        vector<int>lps(m,0);
        lps[0]=0;
        int i=1;
        int length=0;
        while(i<m){
            if (pat[i]==pat[length]){
                length++;
                lps[i]=length;
                i++;
            }
            else{
                if (length==0){
                    lps[i]=0;
                    i++;
                }
                else{
                    length=lps[length-1];
                }
            }
        }
        
        // kmp 
        vector<int>ans;
        i=0;
        int j=0;
        while(i<n){
            if (text[i]==pat[j]){
                i++;
                j++;
            }
            else{
                if(j==0){
                    i++;
                }
                else{
                    j=lps[j-1];
                }
            }
            
            if (j==m){
                ans.push_back(i-j);
                j=lps[j-1];
            }
        }
        
        return ans;
        
    }
};