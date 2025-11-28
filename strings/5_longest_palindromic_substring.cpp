#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string make_palindrome_from_center(string s , int left , int right){
        int n=s.size();
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,(right-left-1));
    }

    string longestPalindrome(string s) {
        
        // very good question 
        // we can start from each index as center of both odd and even palindromes
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            string odd=make_palindrome_from_center(s,i,i);
            string even=make_palindrome_from_center(s,i,i+1);
            // cout<<odd<<" -- "<<even<<endl;
            if (ans.size()<odd.size()) ans=odd;
            if (ans.size()<even.size()) ans=even;
        }
        return ans;
    }
};