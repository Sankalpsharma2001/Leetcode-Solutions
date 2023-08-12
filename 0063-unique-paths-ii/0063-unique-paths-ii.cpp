class Solution {
public:
int countPath(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<int>>& dp)
    {
        if(i>=n or j>=m or grid[i][j]==1) return 0;
       if(i==n-1 and j==m-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=countPath(grid,i+1,j,n,m,dp)+countPath(grid,i,j+1,n,m,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return countPath(grid,0,0,n,m,dp);
    }
};