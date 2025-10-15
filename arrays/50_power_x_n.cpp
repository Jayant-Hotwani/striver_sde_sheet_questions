#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define ll long long 
    double myPow(double x, int n) {

        double ans=1.00;
        ll nn =n;
        if (n<0){
            nn=nn*-1;
        }
        while(nn>0){
            if (nn%2==0){
                x=x*x;
                nn=nn/2;
            }
            else{
                ans=ans*x;
                nn=nn-1;
            }
        }
        if (n<0) return (double)1.00/ans;
        return ans;
    }
};

int main() {
    Solution sol;
    double x = 2.0;
    int n = 10;
    double result = sol.myPow(x, n);
    cout << "Result: " << result << endl; // Output: Result: 1024
    return 0;
}