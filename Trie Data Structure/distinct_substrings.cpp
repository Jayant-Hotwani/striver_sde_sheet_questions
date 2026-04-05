#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[26];
    public:
    TrieNode(){
        for(int i=0;i<26;i++)
        children[i]=NULL;      
    }
};


class Solution {
  public:
    int countSubs(string& s) {
        // code here
        vector<string>all_substrings;
        TrieNode* root=new TrieNode();
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            string curr="";
            TrieNode* temp=root;
            for(int j=i;j<n;j++){
                curr+=s[j];
                int index=s[j]-'a';
                if(temp->children[index]==NULL){
                    ans++;
                    all_substrings.push_back(curr);
                    temp->children[index]=new TrieNode();
                }
                temp=temp->children[index];
            }
        }
        
        return ans;
    }
    
};