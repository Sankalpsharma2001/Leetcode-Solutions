class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& c,int i,
            int j,vector<vector<int>> &dp)
    {
        if(i==grid.size()-1)
            return grid[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int t=1e9;
        for(int k=0;k<grid[0].size();k++)
        {
            t=min(t,grid[i][j]+c[grid[i][j]][k]+dfs(grid,c,i+1,k,dp));
        }
        return dp[i][j]=t;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
     
        int ans=1e9;
        vector<vector<int>> dp(1001,vector<int>(1001,-1));
        for(int i=0;i<grid[0].size();i++)
        {
            int x=dfs(grid,moveCost,0,i,dp);
            ans=min(ans,x);
        }
        return ans;
    }
};