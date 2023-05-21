#define ss second
#define ff first
class Solution {
public:
    int n,m;
    vector<vector<int>> vis;
    queue<pair<int,int>> q;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        vis[i][j]=1;
        q.push({i,j});
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 and y>=0 and x<n and y<m)
            {
                if(grid[x][y] and !vis[x][y])
                {
                    dfs(grid,x,y);
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        bool flag=false;
        vis.resize(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j);
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        // pushes all the (i,j) in queue then calculate min dis from all element in queue to another island
        int dis=0;
        while(!q.empty())
        {
            dis++;
            int sz=q.size();
            while(sz--)
            {
                auto it=q.front();
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int xx=it.ff+dx[k];
                    int yy=it.ss+dy[k];
                    if(xx>=0 and yy>=0 and xx<n and yy<m  )
                    {
                        if(grid[xx][yy]==1 and !vis[xx][yy])
                        {
                            return dis-1;
                        }
                        else if(grid[xx][yy]==0 and !vis[xx][yy])
                        {
                            vis[xx][yy]=1;
                            q.push({xx,yy});
                        }
                    }
                    
                }
            }
                
        }
        return -1;
    }
};