#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, 
    vector<string>& wordList) {


        map<string,int>mp;
        for(auto x:wordList){
            mp[x]++;
        }
        vector<vector<string>>ans;
        queue<vector<string>>q;

        q.push({beginWord});
        while(!q.empty()){
            int sz=q.size();
            vector<string>removed;
            while(sz--){
                vector<string>v=q.front();
                q.pop();
                string str=v.back();
                if(str==endWord){
                    if (ans.size()==0)
                    ans.push_back(v);
                    else{
                        if (ans[0].size()==v.size())
                        ans.push_back(v);
                    }
                }

                for(int i=0;i<str.size();i++){
                    char orig=str[i];
                    for(char ch='a';ch<='z';ch++){
                        if (ch==orig)continue;
                        str[i]=ch;
                        if (mp.find(str)!=mp.end()){
                            v.push_back(str);
                            removed.push_back(str);
                            q.push(v);
                            v.pop_back();
                        }
                    }
                    str[i]=orig;
                }  
            }  
            for(auto x:removed){
                mp.erase(x);
            }
        }
        return ans;
    }
};