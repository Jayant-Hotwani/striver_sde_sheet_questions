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
        
        // basically we are findinf longest panlidromic prefix 
        
        // int ans=0;
        // int n=s.size();
        // while(ispal(s,0,n-1)==false){
        //     ans++;
        //     s.pop_back();
        // }
        // return ans;
        
        // better optimization can be kmp
        
        // what can we do , to find longest palindromic prefix in less time
        // append reverse of string and find lps 
        // lomgest palindromic prefix will be longest panlindromic suffix also 
        // lps[n-1] will give longest palindromic prefix/suffix
        
        int orig_length=s.size();
        string temp=s;
        reverse(temp.begin(),temp.end());
        s+='#';
        s+=temp;
        int n=s.size();
        // lets compute lps 
        vector<int>lps(n,0);
        lps[0]=0;
        int length=0;
        int i=1;
        while(i<n){
            if (s[i]==s[length]){
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
        
        return orig_length-lps[n-1]; 
    }
};

int main(){
    Solution sol;
    string s = "abc";
    cout << sol.minChar(s) << endl; // Output: 2
    return 0;
}
