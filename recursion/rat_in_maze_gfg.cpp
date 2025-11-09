#include <bits/stdc++.h>
using namespace std;
// Function to find all possible paths for a rat to move from the top-left corner to the bottom-right corner of a maze.
// maze: 2D grid representing the maze where 1 is open cell and 0 is blocked cell
// Returns a vector of strings where each string represents a path using 'U', 'D', 'L', 'R' for Up, Down, Left, Right moves.
// Example usage:
// vector<vector<int>> maze = {{1, 0, 0, 0},
//                                 {1, 1, 0, 1},
//                                 {1, 1, 0, 0},
//                                 {0, 1, 1, 1}};   
// Solution sol;
// vector<string> paths = sol.ratInMaze(maze);
// if(paths.empty()){
//     cout << "-1" << endl;
// } else {
//     for(auto path : paths){
//         cout << path << " ";
//     }
//     cout << endl;
// }
// Time Complexity: O(4^(N*N)) in the worst case, where N is        
// the size of the maze (N x N).
// Space Complexity: O(N*N) for the recursion stack and path storage.

class Solution {
  public:
    
    vector<string>ans;
    void dfs(int i,int j ,vector<vector<int>>& maze ,int n,string str){
        
        if (i < 0 || i >= n || j < 0 || j >= n || maze[i][j] != 1)
            return;

        // Destination reached
        if (i == n - 1 && j == n - 1) {
            ans.push_back(str);
            return;
        }

        // Mark visited
        maze[i][j] = 2;

        // Explore 4 directions
        dfs(i + 1, j, maze, n, str + 'D');
        dfs(i - 1, j, maze, n, str + 'U');
        dfs(i, j + 1, maze, n, str + 'R');
        dfs(i, j - 1, maze, n, str + 'L');

        // Unmark visited
        maze[i][j] = 1;
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        if (maze[0][0] == 0) return {};
        string temp="";
        int n=maze.size();
        dfs(0,0,maze,n,temp);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
int main(){
    Solution sol;
    int n;
    cin>>n;
    vector<vector<int>> maze(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    vector<string> result = sol.ratInMaze(maze);
    if(result.empty()){
        cout<<"-1"<<endl;
    }else{
        for(auto path : result){
            cout<<path<<" ";
        }
        cout<<endl;
    }
    return 0;
}