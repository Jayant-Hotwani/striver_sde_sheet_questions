#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[26];
    int count_ends_with=0;
    int count_prefix=0;
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
        root = new TrieNode();
    }
    void insert(string s){
        TrieNode* temp=root;
        for(auto x:s){
            int index=x-'a';
            if (temp->children[index]==NULL){
                temp->children[index]=new TrieNode();
            }
            temp=temp->children[index];
            temp->count_prefix++;
        }

        temp->count_ends_with++;
    }


    void erase(string s){
        if(countWordsEqualTo(s) == 0) return;
        TrieNode* temp=root;
        for(auto x:s){
            int index=x-'a';
            if (temp->children[index]==NULL){
                return;
            }
            temp=temp->children[index];
            temp->count_prefix--;
        }

        temp->count_ends_with--;
    }


    int countWordsStartingWith(string s){
        TrieNode* temp=root;
        for(auto x:s){
            int index=x-'a';
            if (temp->children[index]==NULL){
                return 0;
            }
            temp=temp->children[index];
        }
        return temp->count_prefix;
    }
    int countWordsEqualTo(string s){
        TrieNode* temp=root;
        for(auto x:s){
            int index=x-'a';
            if (temp->children[index]==NULL){
                return 0;
            }
            temp=temp->children[index];
        }
        return temp->count_ends_with;
    }
};

int main(){
    Trie trie;

    trie.insert("apple");
    trie.insert("apple");
    trie.insert("app");

    cout << trie.countWordsEqualTo("apple") << endl; // 2
    cout << trie.countWordsEqualTo("app") << endl;   // 1

    cout << trie.countWordsStartingWith("app") << endl; // 3

    trie.erase("apple");

    cout << trie.countWordsEqualTo("apple") << endl; // 1

    return 0;
}