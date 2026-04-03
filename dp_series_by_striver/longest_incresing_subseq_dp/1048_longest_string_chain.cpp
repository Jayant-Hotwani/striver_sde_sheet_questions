#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool mycmp(string& a , string& b){
        return a.size()<b.size();
    }

    bool check(string& s , string& t){
        if(s.size()!=t.size()+1)return false;
        int index1=0;
        int index2=0;
        while(index1!=s.size()){
            if (index2<t.size() && s[index1]==t[index2]){
                index1++;
                index2++;
            }
            else
            {
                index1++;
            }
        }

        if (index2!=t.size())return false;
        return true;

    }

    int longestStrChain(vector<string>& words) {

        int n=words.size();
        int len=1;
        sort(words.begin(),words.end(),mycmp);
        vector<int>dp(n,1);
        for(int index=0;index<n;index++){
            for(int prev=0;prev<index;prev++){
                if(check(words[index],words[prev])==true){
                    if (dp[index]<1+dp[prev]){
                        dp[index]=1+dp[prev];
                    }
                }
            }
            len=max(len,dp[index]);
        }
        return len;
    }
};