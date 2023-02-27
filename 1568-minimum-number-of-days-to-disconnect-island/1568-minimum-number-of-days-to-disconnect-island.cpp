class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j] || grid[i][j]==0)              return;
        vis[i][j]=1;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        for(int dir=0;dir<4;dir++)
        {
            int x=i+dx[dir];
            int y=j+dy[dir];
            
            dfs(x,y,vis,grid);
        }
        
        
    }
    int countIsland(vector<vector<int>>& grid)
    {
        int n=grid.size(),m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j])
                {
                    if(grid[i][j])
                    {
                    dfs(i,j,vis,grid);
                    cnt++;
                    }
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int island=countIsland(grid);
        if(island>1 || island==0)
            return 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    grid[i][j]=0;
                    int c=countIsland(grid);
                    grid[i][j]=1;
                    if(c>1 || c==0)
                        return 1;
                }
            }
        }
        return 2;
    }
};