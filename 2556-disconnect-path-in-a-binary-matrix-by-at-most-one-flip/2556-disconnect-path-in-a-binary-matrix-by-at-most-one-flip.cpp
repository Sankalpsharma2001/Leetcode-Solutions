class Solution {
public:
    bool dfs(int x,int y,vector<vector<int>>& grid)
    {
         int n=grid.size();
        int m=grid[0].size();
        if(x==n-1 && y==m-1)
            return true;
        if(x>=n || y>=m || grid[x][y]==0) return false;
        grid[x][y]=0;
       return dfs(x+1,y,grid) ||   dfs(x,y+1,grid);
      
        
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        if(dfs(0,0,grid)==false) return true; //  no path from 0,0 to n-1,m-1
        grid[0][0]=1;
        return dfs(0,0,grid)==false;
    }
};