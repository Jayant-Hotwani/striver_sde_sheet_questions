#include <bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd=false;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};

class Trie{
  public:
  TrieNode* root;
  Trie(){
     root=new TrieNode();
  }
  
  void insert(string s){
      TrieNode* temp=root;
      for(auto x:s){
          int index=x-'a';
          if (temp->children[index]==NULL){
              temp->children[index]=new TrieNode();
          }
          temp=temp->children[index];
      }
      temp->isEnd=true;
  }
  bool checkIfAllPrefixExists(string s){
      TrieNode* temp=root;
      for(auto x:s){
          int index=x-'a';
          if (temp->children[index]==NULL){
              return false;
          }
          temp=temp->children[index];
          if(temp->isEnd==false)return false;
      }
     return temp->isEnd;
  }
  
};

class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
        Trie trie;
        for(auto x:words)
        trie.insert(x);
        
        string ans="";
        for(auto x:words){
            if(trie.checkIfAllPrefixExists(x)){
                if (ans.size()==0)
                ans=x;
                else{
                    if(ans.size()<x.size())ans=x;
                    else if (ans.size()==x.size() && x<ans)ans=x;
                }
            }
        }
        return ans;
    }
};