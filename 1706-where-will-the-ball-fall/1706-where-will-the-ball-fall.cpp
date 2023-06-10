class Solution {
public:
    bool isValid(int x,int y,int m,int n)
    {
        return x>=0 && y>=0 && x<m && y<n;
    }
    int dfs(int i,int j,vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i==m) return j;
        if(isValid(i,j,m,n))
        {
            if(grid[i][j]==1)
            {
                if(isValid(i,j+1,m,n) && grid[i][j+1]==1)
                {
                    return dfs(i+1,j+1,grid);
                }
            }
            else
            {
                if(isValid(i,j-1,m,n) && grid[i][j-1]==-1)
                {
                    return dfs(i+1,j-1,grid);
                }
            }
        }
        return -1;
        
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            int res=dfs(0,i,grid);
            ans[i]=res;
        }
        return ans;
    }
};