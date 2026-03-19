#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int steps=0;
        map<string,int>mp;
        for(auto x:wordList){
            mp[x]++;
        }
        queue<string>q;
        q.push(beginWord);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
            auto s=q.front();
            q.pop();
            if(s==endWord){
                return steps+1;
            }
            for(int i=0;i<s.size();i++){
                    char ch=s[i];
                    for(char c ='a' ; c<='z';c++){
                        if(c==ch)continue;
                        s[i]=c;
                        if (mp.find(s)!=mp.end()){
                            q.push(s);
                            mp.erase(s);
                        }
                    }
                    s[i]=ch;
                } 
            }
            steps++;
        }
        return 0;
    }

};