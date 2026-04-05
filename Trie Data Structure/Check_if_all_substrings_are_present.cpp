#include <bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isEnd=false;
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

    bool search(string s){
        TrieNode* temp=root;
        for(auto x:s){
            int index =x-'a';
            if(temp->children[index]==NULL)return false;

            temp=temp->children[index];
        }
        return temp->isEnd==true;
    }

    bool startsWith(string s){
        TrieNode* temp=root;
        for(auto x:s){
            int index =x-'a';
            if(temp->children[index]==NULL)return false;

            temp=temp->children[index];
        }
        return true;
    }
};

class Solution {
public:
    bool checkAllSubstrings(string s, vector<string>& dict) {
        Trie trie;
        // Insert dictionary words
        for(auto &word : dict){
            trie.insert(word);
        }

        int n=s.size();
        for(int i=0;i<n;i++){
            TrieNode* node=trie.root;
            for(int j=i;j<n;j++){
                int index=s[j]-'a';
                if(node->children[index]==NULL)return false;

                node=node->children[index];
                if(!node->isEnd)
                    return false;
            }
        }
        return true;
    }
};


int main(){
    // 🔹 Problem testing
    Solution sol;

    string s = "abc";
    vector<string> dict = {"a","b","c","ab","bc","abc"};

    if(sol.checkAllSubstrings(s, dict)){
        cout << "All substrings valid\n";
    } else {
        cout << "Invalid substring found\n";
    }

    return 0;
}