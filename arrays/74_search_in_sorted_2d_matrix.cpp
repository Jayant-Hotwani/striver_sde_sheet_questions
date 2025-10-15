#include <bits/stdc++.h>
using namespace std;

// Search in a 2D matrix
// we can do this by starting from the top right corner of the matrix
// if the target is greater than the current element then we can move down
// if the target is less than the current element then we can move left
// if we find the target then we can return true
// if we reach the end of the matrix then we can return false
// time complexity O(m+n)
// space complexity O(1)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1;

        while (i < m && j >= 0)
        {
            if (target == matrix[i][j])
                return true;
            else if (target > matrix[i][j])
                i++;
            else if (target < matrix[i][j])
                j--;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    bool found = sol.searchMatrix(matrix, target);
    if (found)
        cout << "Element found";
    else
        cout << "Element not found";
    return 0;
}