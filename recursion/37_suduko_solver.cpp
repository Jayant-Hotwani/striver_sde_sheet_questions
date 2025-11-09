#include <bits/stdc++.h>
using namespace std;

// Sudoku Solver using Backtracking
// Time Complexity: O(9^(n*n)) in worst case
// Space Complexity: O(1) as we are modifying the board in place

class Solution {
public:

    bool isValid(vector<vector<char>>& board,int row , int col , char c)
    {
        for (int i=0;i<9;i++)
        {
            if (board[i][col]==c) return false;
            if (board[row][i]==c) return false;
            if (board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
                return false;
        }
        return true;
        
    }

    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if (board[i][j]=='.')
                {
                    for(char ch='1';ch<='9';ch++){
                        if (isValid(board,i,j,ch)){
                            board[i][j]=ch;
                            if (solve(board))return true;
                            else
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main(){
    Solution sol;
    vector<vector<char>> board(9,vector<char>(9));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>board[i][j];
        }
    }
    sol.solveSudoku(board);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
