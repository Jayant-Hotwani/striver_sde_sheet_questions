#include<bits/stdc++.h>
using namespace std;
// leetcode longest substring without repeating characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// approach : sliding window with hashmap to store last occurrence index of characters
// for each character checking if it has appeared in the current window or not
// if yes then moving the start of the window to the right of its last occurrence
// updating the maximum length of substring accordingly
// time complexity : O(n)
// space complexity : O(min(m,n)) where m is the size of charset and n is length of string  

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // O(2N)

        int n=s.size();
        if (s.size()==0) return 0;
        // int ans=1;
        // map<char,int>mp;
        // int i=0,j=0;
        // while(j<n){
        //   while(i<j && mp.find(s[j])!=mp.end()){
        //     mp[s[i]]--;
        //     if(mp[s[i]]==0) mp.erase(s[i]);
        //     i++;
        //   }
        //   mp[s[j]]++;
        //   ans=max(ans,j-i+1);
        //   j++;
        // }
        // return ans;

        // more better 
        
        int ans=1;
        map<char,int>mp;
        int i=0;int j=0;
        while(j<n){
            if (mp.find(s[j])!=mp.end()){
                i=max(i,mp[s[j]]+1);
            }
            ans=max(ans,j-i+1);
            mp[s[j]]=j;
            j++;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string s="abcabcbb";
    cout<<sol.lengthOfLongestSubstring(s);
    return 0;
}