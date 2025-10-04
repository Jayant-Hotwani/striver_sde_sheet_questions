#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
#define ll long long
    // code to find nCr

    ll ncr(ll n, ll r)
    {

        ll res = 1;
        for (int i = 0; i < r; i++)
        {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }

    // code to get nth row
    vector<int> get_nth_row(ll n)
    {
        vector<int> v;
        v.push_back(1);
        ll ans = 1;
        for (int i = 1; i < n; i++)
        {
            ans = ans * (n - i);
            ans = ans / i;
            v.push_back(ans);
        }

        return v;
    }

    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> ans;
        // cout<<ncr(4,2)<<endl;
        for (int i = 1; i <= numRows; i++)
        {
            vector<int> v = get_nth_row(i);
            ans.push_back(v);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int numRows = 5;
    vector<vector<int>> pascalTriangle = sol.generate(numRows);
    for (const auto &row : pascalTriangle)
    {
        for (int val : row)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}