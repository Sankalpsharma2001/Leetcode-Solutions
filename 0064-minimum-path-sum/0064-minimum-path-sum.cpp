class Solution {
public:
    // int solve(int x,int y,vector<vector<int>>& grid,vector<vector<int>> &dp)
    // {
    //      int m=grid.size(),n=grid[0].size();
    //     if(x<0 || y<0 || x>=m || y>=n) return 1e9;
    //     if(x==m-1 && y==n-1)
    //         return grid[x][y];
    //     if(dp[x][y]!=-1)
    //         return dp[x][y];
    //     int r=grid[x][y]+solve(x,y+1,grid,dp);
    //     int d=grid[x][y]+solve(x+1,y,grid,dp);
    //     return dp[x][y]=min(r,d);
    // }
    int minPathSum(vector<vector<int>>& grid) {
     int m=grid.size(),n=grid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
       // return solve(0,0,grid,dp); 
        
        vector<vector<int>> dp(m,vector<int>(n,0));
     
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=grid[i][j];
                    continue;
                }
                else
                {
                int r=grid[i][j],d=grid[i][j];
          if(j>0)  
         r+=dp[i][j-1];   
        else
         r+=1e9;
                    
            if(i>0)    
         d+=dp[i-1][j];
           else
           d+=1e9;
         dp[i][j]=min(r,d);
            }
                
        }
        }
        return dp[m-1][n-1];
    }
};