#include <bits/stdc++.h>
using namespace std;

// Function to partition a string such that every substring is a palindrome
// s: input string
// Returns a vector of vectors containing all possible palindrome partitioning of s
// Link: https://leetcode.com/problems/palindrome-partitioning/
// Example:
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Explanation: There are two palindrome partitioning of "aab".
// TC: O(n*2^n) SC: O(n)
// where n is the length of the input string

class Solution {
public:
    vector<vector<string>> ans;
    bool ispal(string& s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if (s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }

    // Recursive function to generate palindrome partitions
    // index: current index in the string
    // s: input string
    // ds: current partition being formed
    // n: length of the string  


    void dfs( int index , string s , vector<string>& ds, int n){
        if (index>=n){
            ans.push_back(ds);
            return ;
        }

        string str="";
        for(int i=index;i<n;i++){
            str+=s[i];
            if (ispal(str)){
                ds.push_back(str);
                dfs(i+1,s,ds,n);
                ds.pop_back();
            }
        }
        
    }

 // Main function to initiate the partitioning process
 // s: input string
 // Returns a vector of vectors containing all palindrome partitioning of s 
    vector<vector<string>> partition(string s) {

        vector<string>ds;
        int n=s.size();
        dfs(0,s,ds,n);
        return ans;
    }
};

int main() {
    Solution solution;
    string s = "aab";
    vector<vector<string>> partitions = solution.partition(s);
    std::cout << "Palindrome partitions of \"" << s << "\":" << std::endl;
    for (const auto& partition : partitions) {
        std::cout << "[";
        for (size_t i = 0; i < partition.size(); ++i) {
            std::cout << partition[i];
            if (i < partition.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}