#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        vector<string>key={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int>value={1000,900,500,400,100,90,50,40,10,9,5,4,1};

        string ans="";
        for(int i=0;i<key.size();i++){
            while(num>=value[i]){
                num-=value[i];
                ans+=key[i];
            }
        }
        return ans;
    }
};