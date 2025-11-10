#include <bits/stdc++.h>
using namespace std;
// Function to find all possible sentences by segmenting a string into valid dictionary words.
// s: input string
// wordDict: list of valid dictionary words
// Returns a vector of strings where each string represents a valid sentence formed by segmenting the input
// string into dictionary words.
// Example usage:
// string s = "catsanddog";
// vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
// Solution sol;
// vector<string> sentences = sol.wordBreak(s, wordDict);
// for(auto sentence : sentences){
//     cout << sentence << endl;
// }
// Time Complexity: O(N^2 * M) in the worst case, where N is the length of the string and M is the number of words in the dictionary.
// Space Complexity: O(N) for the recursion stack and result storage.

class Solution {
public:
    vector<string> ans;
    void dfs(int index, string& s,map<string,int>& mp, string temp){
        if (index>=s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }

        string str="";
        for(int i=index;i<s.size();i++){
            str+=s[i];
            if(mp.find(str)!=mp.end()){
                str+=' ';
                dfs(i+1,s,mp,temp+str);
                str.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string,int>mp;
        for(auto x:wordDict){
            mp[x]++;
        }
        string temp="";
        dfs(0,s,mp,temp);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    Solution sol;
    string s;
    int n;
    cin>>s;
    cin>>n;
    vector<string> wordDict(n);
    for(int i=0;i<n;i++){
        cin>>wordDict[i];
    }
    vector<string> result = sol.wordBreak(s,wordDict);
    for(auto x:result){
        cout<<x<<endl;
    }
    return 0;
}