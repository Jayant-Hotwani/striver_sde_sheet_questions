#include <iostream>
#include <vector>   
#include <algorithm>
using namespace std;

// rotate the image by 90 degree clockwise
// we can do this by using extra space
// but optimal way is to do this in place
// we can do this by first transposing the matrix and then reversing each row   
// to transpose the matrix we can swap the elements at (i,j) with (j,i) for all i<j
// then we can reverse each row to get the final result
// time complexity O(n^2)
// space complexity O(1)


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // brute force using extra space;
        int n=matrix.size();
        // vector<vector<int>>ans(n,vector<int>(n));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         ans[j][n-i-1]=matrix[i][j];
        //     }
        // }
        // matrix=ans;
        
        // not the optimal way to do , because we have used extra space
        // optimal solution is transpose+ reverse rows;
        // how to transpose , evrything on daigonal remains same and rest reverses 

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }

    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    sol.rotate(matrix);
    for(auto row: matrix){
        for(auto col: row){
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}