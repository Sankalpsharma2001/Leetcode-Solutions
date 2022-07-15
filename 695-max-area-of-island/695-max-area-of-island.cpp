class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
   int n,m;
    int area=0;
    void solve(vector<vector<int>>& grid,int i,int j)
    {
       
         if(i>=0 and j>=0 and i<n and j<m and grid[i][j] )
         {
          grid[i][j]=0;
             area++;
             solve(grid,i+1,j);
             
             solve(grid,i,j+1);
             
             solve(grid,i,j-1);
             
             solve(grid,i-1,j);
      
         }
      
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            { if(grid[i][j])
                area=0;
             solve(grid,i,j);
                ans=max(ans,area);
            }
        }
        return ans;
    }
};