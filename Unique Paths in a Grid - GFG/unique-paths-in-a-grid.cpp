//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int mod=1e9+7;
  int countPaths(int x,int y,int n,int m,vector<vector<int>> &grid,vector<vector<int>> &dp)
  {
      if(x<0 || y<0 || x>=n || y>=m || grid[x][y]==0) return 0;
      if(x==n-1 && y==m-1) return 1;
      if(dp[x][y]!=-1) return dp[x][y];
      int ans=0;
      ans+=countPaths(x+1,y,n,m,grid,dp)%mod+countPaths(x,y+1,n,m,grid,dp)%mod;
      return dp[x][y]=ans%mod;
  }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return countPaths(0,0,n,m,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends