#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    #define ll long long 
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        while(i<n && s[i]==' '){
            i++;
        }
        if (i==n) return 0;
        ll maxi=INT_MAX;
        ll mini=INT_MIN;
        int sign=1;
        if (s[i]=='-'){
            i++;
            sign=-1;
        }
        else if (s[i]=='+')
        {
            i++;
        }
        ll res=0;
        while(i<n && isdigit(s[i])){
            int digit=(int)s[i]-'0';
            res=res*10+(digit);
            if(sign*res>=maxi)return maxi;
            if(sign*res<=mini)return mini;
            i++;
        }

        return static_cast<int>(sign*res);
    }
};