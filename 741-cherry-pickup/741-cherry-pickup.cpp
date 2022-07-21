class Solution {
public:
    int solve(vector<vector<int>>& grid,int i1,int j1,int i2,int j2,vector<vector<vector<vector<int>>>> &dp)
    {
        int m=grid[0].size(),n=grid.size();
        // int i2=j1+i1-j2;
        
if(j1>=m || i1>=n || j2>=m || i2>=n || grid[i1][j1]==-1 || grid[i2][j2]==-1)
            return -1e8;
        if(dp[i1][j1][i2][j2]!=-1)
            return dp[i1][j1][i2][j2];
        if(i1==n-1 and j1==m-1)
        {
            return grid[i1][j1];
        }
        
        int x=0;
        if(i1!=i2)
            x=grid[i1][j1]+grid[i2][j2];
        else
             x=grid[i1][j1];
      // P1     |      P2
    //   DOWN    |     DOWN
    //   DOWN    |     RIGHT
    //   RIGHT   |     DOWN
    //   RIGHT   |     RIGHT
        x+=max({solve(grid,i1+1,j1,i2+1,j2,dp),solve(grid,i1+1,j1,i2,j2+1,dp),
               solve(grid,i1,j1+1,i2+1,j2,dp),solve(grid,i1,j1+1,i2,j2+1,dp)
                });
        return dp[i1][j1][i2][j2]=x;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
 vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(m,-1))));
return max(0,solve(grid,0,0,0,0,dp));        
    }
};