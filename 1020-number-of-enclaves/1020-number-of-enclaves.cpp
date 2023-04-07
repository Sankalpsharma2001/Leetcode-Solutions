class Solution {
public:
    int ans=0;
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
      if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0)
      return;
      ans++;
      grid[i][j]=0;
      dfs(grid,i+1,j,n,m);
      dfs(grid,i-1,j,n,m);
      dfs(grid,i,j-1,n,m);
      dfs(grid,i,j+1,n,m);
    }
    int numEnclaves(vector<vector<int>>& grid) {
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