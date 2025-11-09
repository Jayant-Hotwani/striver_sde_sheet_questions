#include <bits/stdc++.h>
using namespace std;
// Function to determine if a string can be segmented into a space-separated sequence of one or more
// dictionary words.
// s: input string
// wordDict: list of valid dictionary words
// Returns true if the string can be segmented, false otherwise.
// Example usage:
// string s = "leetcode";
// vector<string> wordDict = {"leet", "code"};
// Solution sol;
// bool canSegment = sol.wordBreak(s, wordDict);
// cout << (canSegment ? "true" : "false") << endl;
// Time Complexity: O(N^2 * M) where N is the length of the string and M is the average length of words in the dictionary.
// Space Complexity: O(N) for the dp array and recursion stack. 
class Solution {
public:
    int dp[301];
    // Depth-First Search function to check segmentation
    // index: current index in the string
    // s: input string
    // mp: map of dictionary words for quick lookup 
    // Returns true if the substring from index to end can be segmented
    // into dictionary words.
    
    bool dfs(int index,string s, map<string,int>& mp){
        if(index>=s.size()){
            return dp[index]= true;
        }

        if (dp[index]!=-1){
            return dp[index];
        }

        string str="";
        for(int i=index;i<s.size();i++){
            str+=s[i];
            if(mp.count(str)){
                if (dfs(i+1,s,mp)) return true;
            }
        }

        return dp[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        map<string,int>mp;
        for(auto x:wordDict){
            mp[x]++;
        }
        return dfs(0,s,mp);
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
    if(sol.wordBreak(s,wordDict)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}