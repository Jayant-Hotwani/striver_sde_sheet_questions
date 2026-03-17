#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    vector<int>indeg(n+1,0);
	    for (int i=0;i<n;i++)
	    {
	        for (auto it:adj[i])
	        indeg[it]++;
	    }
	    
	    queue<int>q;
	    for (int i=0;i<n;i++){
	        if (indeg[i]==0)
	        q.push(i);
	    }
	    
	    vector<int>ans;
	    while(!q.empty())
	    {
	        auto x=q.front();
	        q.pop();
	        ans.push_back(x);
	        for (auto it :adj[x])
	        {
	            indeg[it]--;
	            if (indeg[it]==0)
	            q.push(it);
	        }
	    }
	    
	    return ans;
	}
};