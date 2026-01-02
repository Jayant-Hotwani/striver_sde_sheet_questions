#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isValidSerialization(string s) {

        int slots=1;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==',') continue;
            if(slots<=0) return false;
            if(s[i]=='#')slots--;
            else{
                while(i<n && s[i]!=','){
                    i++;
                }
                slots+=2;
                slots-=1;
            }
        }
        return slots==0;    
    }
};