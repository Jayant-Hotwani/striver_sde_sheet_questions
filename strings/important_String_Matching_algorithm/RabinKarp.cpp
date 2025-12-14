#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define ll long long 
    int strStr(string text, string pattern) {

        ll n=text.size();
        ll k=pattern.size();
        if (n<k) return -1;
        ll mod=1e9+7;
        ll base=26;
        ll highest_power=1;
        for(int i=0;i<k-1;i++){
            highest_power=((highest_power)*base);
            highest_power%=mod;
        }
        ll pattern_hash=0;
        for(int i=0;i<k;i++){
            pattern_hash=((pattern_hash*base)+(pattern[i]-'a'))%mod;
        }

        ll text_hash=0;
        for(int i=0;i<k;i++){
            text_hash=((text_hash*base)+(text[i]-'a'))%mod;
        }

        if (text_hash==pattern_hash) return 0;
        for(int i=k;i<n;i++){
            ll temp=highest_power*(text[i-k]-'a')%mod;
            text_hash=(text_hash-(temp)+mod)%mod;
            text_hash=((text_hash*base)%mod + (text[i]-'a'))%mod;
            if (text_hash==pattern_hash) return (i-k+1);
        }
        return -1;
    }
};