class Solution {
public:
   void dfs(vector<vector<char>> &grid,int i,int j)
   {
 if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()  || grid[i][j]=='0') return;
       grid[i][j]='0';
       int dx[]={1,-1,0,0};
       int dy[]={0,0,-1,1};
       for(int k=0;k<4;k++)
       {
          int newx=dx[k]+i;
          int newy=dy[k]+j;
          dfs(grid,newx,newy);
       }
   }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};