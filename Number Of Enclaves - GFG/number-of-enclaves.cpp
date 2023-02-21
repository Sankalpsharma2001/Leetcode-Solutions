//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int ans=0;
  int dx[4]={1,-1,0,0};
  int dy[4]={0,0,-1,1};
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
      if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0)
      return;
      ans++;
      grid[i][j]=0;
      for(int dir=0;dir<4;dir++)
      {
          int newX=i+dx[dir];
          int newY=j+dy[dir];
          dfs(grid,newX,newY,n,m);
      }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
         int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]) dfs(grid,i,0,n,m);
            if(grid[i][m-1]) dfs(grid,i,m-1,n,m);
        }
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]) dfs(grid,0,i,n,m); 
            if(grid[n-1][i]) dfs(grid,n-1,i,n,m);
        }
         ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(grid[i][j])
               dfs(grid,i,j,n,m);
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends