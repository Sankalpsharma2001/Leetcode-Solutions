class Solution {
public:
    bool isValid(int x,int y,int n,int m)
    {
        return x>=0 && y>=0 && x<n && y<m;
     }
    bool check(int x,int y,int height ,vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
          int n=grid.size(),m=grid[0].size();
        vis[x][y]=1;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        for(int dir=0;dir<4;dir++)
        {
            int newX=x+dx[dir];
            int newY=y+dy[dir];
            if(isValid(newX,newY,n,m))
            {
                if(vis[newX][newY]==0 && grid[newX][newY]<=height)
                {
                    if(newX==n-1 && newY==m-1)
                        return true;
                if(check(newX,newY,height,vis,grid))
                    return true;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
      int n=grid.size(),m=grid[0].size();
        
       int low=grid[0][0],high=1e9,ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            vector<vector<int>> vis(n,vector<int>(m,0));
            if(check(0,0,mid,vis,grid))
            {
                ans=mid;
                high=mid-1;
                
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};