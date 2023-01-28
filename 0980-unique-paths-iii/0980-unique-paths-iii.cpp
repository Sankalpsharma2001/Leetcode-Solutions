class Solution {
public:
    int n,m,ans;
    bool isNotValid(int x,int y)
    {
        return x<0 || y<0 || x>=n || y>=m;
    }
    void findPaths(vector<vector<int>>& grid,vector<vector<int>>& vis,int x,int y,int totalPath)
    {
        if(isNotValid(x,y) || vis[x][y]==1 || grid[x][y]==-1)
        {
            return;
        }
        if(grid[x][y]==2)
        {
            if(totalPath==0) ans++;
            // cout<<ans<<" ";
            return;
        }
        vis[x][y]=1;
        totalPath--;
        findPaths(grid,vis,x+1,y,totalPath);        
        findPaths(grid,vis,x-1,y,totalPath);
        findPaths(grid,vis,x,y+1,totalPath);
        findPaths(grid,vis,x,y-1,totalPath);
        totalPath++;
        vis[x][y]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
         ans=0; 
       
        int totalPath=1; // as starting point we also we have to add
        int x=-1,y=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0) totalPath++;
                if(grid[i][j]==1)
                {x=i,y=j;}
                
            }
        }
        vector<vector<int>> vis(n,vector<int>(m,0));
       findPaths(grid,vis,x,y,totalPath);
        return ans;
        
    }
};