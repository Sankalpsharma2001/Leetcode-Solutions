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
        
        // vector<vector<int>> dp(m,vector<int>(n,0));
     vector<int> pre(n,0);
        for(int i=m-1;i>=0;i--)
        {
            vector<int> cur(n,0);
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1)
                {
                    cur[j]=grid[i][j];
                    continue;
                }
                int r=grid[i][j],d=grid[i][j];
          if(j+1<n)  
         r+=cur[j+1];   
        else
         r+=1e9;
            if(i+1<m)    
         d+=pre[j];
            else
           d+=1e9;
         cur[j]=min(r,d);
            }
            pre=cur;
        }
        return pre[0];
    }
};