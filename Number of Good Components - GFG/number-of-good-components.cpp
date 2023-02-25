//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int edge=0,v=0;
   void dfs(int node,int parent,vector<int> &vis,vector<vector<int>>& adj)
   {
       vis[node]=1;
       v++;
       for(auto it:adj[node])
       {
           edge++;
           if(!vis[it])
           { 
              dfs(it,node,vis,adj);
               
           }
           
       }
     
   }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        vector<int> vis(V+1,0);
        int ans=0;
        for(int i=1;i<=V;i++)
        {
            if(!vis[i])
            {
                edge=0,v=0;
              dfs(i,-1,vis,adj);
              if(edge/2==(v*(v-1))/2)
                ans++;
                // cout<<edge<<" ";
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends