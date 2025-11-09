#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define ll long long 
    static bool mycmp(string& a , string& b){
        ll x=stoll(a);
        ll y=stoll(b);
        return x<y;
    }
    // generate all permutations of numbers from 1 to n
    // store them in a vector and return the kth permutation in sorted order
    // time complexity : O(n! * n log(n!)) due to sorting
    // space complexity : O(n! * n) to store all permutations

    void dfs(int n , string& str,vector<int>& vis,vector<string>& ans){
        if (str.size()==n){
            ans.push_back(str);
            return;
        }

        for(int i=1;i<=n;i++){
            if (vis[i]==0){
                vis[i]=1;
                str+=to_string(i);
                dfs(n,str,vis,ans);
                str.pop_back();
                vis[i]=0;
            }
        }
    }
    // function to find all permutations
    // and store them in a vector
    // return the vector of permutations

    vector<string> find_all_perm( int n , int k){
        vector<int>vis(n+1,0);
        vector<string>ans;
        string str="";
        dfs(n,str,vis,ans);
        return ans;
    }
    // main function to get the kth permutation
    // calls the function to find all permutations
    // sorts them and returns the kth one

    // string getPermutation(int n, int k) {
        
    //     vector<string>v=find_all_perm(n,k);
    //     sort(v.begin(),v.end(),mycmp);
    //     return v[k-1];
    // }



    // main function to get the kth permutation
    
     string getPermutation_optimized(int n, int k) {

        string ans="";
        int fact=1;
        vector<int>numbers;
        for(int i=1;i<n;i++){
            numbers.push_back(i);
            fact=fact*i;
        }
        numbers.push_back(n);

        k=k-1;
        while(1){
            ans+=to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+k/fact);
            if(numbers.empty()) break;
            k=k%fact;
            fact=fact/numbers.size();
        }
        return ans;
    }

};

int main() {
    Solution sol;
    int n, k;
    cin >> n >> k;
    cout << sol.getPermutation_optimized(n, k) << endl;
    return 0;
}