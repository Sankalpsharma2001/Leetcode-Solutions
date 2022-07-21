class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j1,int j2,vector<vector<vector<int>>> &dp)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(j1<0 || j1>=m || j2>=m || j2<0)
            return -1e7;
        if(i==n-1)
        {
            if(j1==j2)
                return grid[i][j1];
            else
                return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        int dy[3]={-1,0,1};
        int temp=-1e7;
        for(int i1=0;i1<3;i1++)
        {
            for(int j=0;j<3;j++)
            {
                int x=0;
                if(j1==j2)
                {
                    x=grid[i][j1];
                }
                else
                {
                    x=grid[i][j1]+grid[i][j2];
                }
                x+=solve(grid,i+1,j1+dy[i1],j2+dy[j],dp);
                temp=max(temp,x);
            }
        }
        return dp[i][j1][j2]=temp;
    }
    int cherryPickup(vector<vector<int>>& grid) {
       int n=grid.size();
        int m=grid[0].size();
vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
return solve(grid,0,0,m-1,dp);
        
        
        
    }
};