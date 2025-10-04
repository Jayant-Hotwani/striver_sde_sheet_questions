
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m= matrix.size();
        int n= matrix[0].size();
        vector<bool>rows(m,false),col(n,false);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (matrix[i][j]==0){
                    rows[i]=true;
                    col[j]=true;
                }
            }
        }

        for (int i=0;i<m;i++){
            if (rows[i]){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            } 
        }

        for (int i=0;i<n;i++){
            if (col[i]){
                for(int j=0;j<m;j++){
                    matrix[j][i]=0;
                }
            } 
        }
        
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    sol.setZeroes(matrix);
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
