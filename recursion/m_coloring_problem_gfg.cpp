#include <bits/stdc++.h>
using namespace std;
// Function to determine if the graph can be colored with at most M colors such that no two adjacent vertices have the same color.
// v: number of vertices
// edges: list of edges where each edge is represented as a pair of vertices
// m: maximum number of colors
// Returns true if the graph can be colored with m colors, false otherwise.
// Example usage:
// int v = 4; // number of vertices
// vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}}; // edges of the graph
// int m = 3; // maximum number of colors
// Solution sol;
// bool canColor = sol.graphColoring(v, edges, m);
// cout << (canColor ? "Graph can be colored" : "Graph cannot be colored") << endl;
// Time Complexity: O(M^V) in the worst case, where M is the number of colors and V is the number of vertices.
// Space Complexity: O(V) for the color array and recursion stack.

class Solution {
  public:
  // Function to check if it's safe to color a node with a given color
    bool isSafe(int node,vector<int> adj[], int v,vector<int>& color,int c){
        for(auto x:adj[node]){
            if (color[x]==c)return false;
        }
        return true;
    }
    // Depth-First Search function to try coloring the graph
    // node: current node to color
    // adj: adjacency list of the graph
    // v: number of vertices
    // m: maximum number of colors
    // color: current color assignment for each vertex  
    bool dfs(int node,vector<int> adj[] , int v , int m , vector<int>& color){
        
        if(node>=v){
            return true;
        }
        for(int i=0;i<m;i++){
            if (isSafe(node,adj,v,color,i)){
                color[node]=i;
                if (dfs(node+1,adj,v,m,color))return true;
                color[node]=-1;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        
        vector<int>adj[v];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>color(v,-1);
        return dfs(0,adj,v,m,color);
        
    }
};

int main(){
    Solution sol;
    int v, m, e;
    cin >> v >> m >> e;
    vector<vector<int>> edges(e, vector<int>(2));
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    if (sol.graphColoring(v, edges, m)) {
        cout << "Graph can be colored with " << m << " colors." << endl;
    } else {
        cout << "Graph cannot be colored with " << m << " colors." << endl;
    }
    return 0;
}