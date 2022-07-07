class Solution {
public:
    int n,m;
    int dp[211][211];
    int solve(vector<vector<int>>& grid,int x,int y)
    {
        if(x==n-1 and y==m-1)
            return grid[x][y];
        if(x<0 or y<0 or x>=n or y>=m) return INT_MAX;
        
        if(dp[x][y]!=-1)
            return dp[x][y];
        int a=solve(grid,x+1,y);
        int b=solve(grid,x,y+1);
        int ans=min(a,b)+grid[x][y];
        return dp[x][y]=ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        memset(dp,-1,sizeof(dp));
       return solve(grid,0,0);
    }
};