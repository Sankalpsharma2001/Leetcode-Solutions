class Solution {
public:
    bool isvalid(int x,int y,vector<vector<int>>& grid)
    {
        return x>=0 and y>=0 and x<grid.size() and y<grid[0].size();
    }
    int orangesRotting(vector<vector<int>>& grid) {
         int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        int c=0;
        for(int i=0;i<n;i++)
        {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]==2)
                   q.push({i,j});
               else if(grid[i][j]==1)
                   c++;
           }
            
        }
        int cnt=0;
        int time=0;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty() and cnt!=c)
        {
            int sz=q.size();
            while(sz--)
            {
                auto t=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int x=t.first+dx[i];
                    int y=t.second+dy[i];
                    if(isvalid(x,y,grid) and grid[x][y]==1)
                    {
                        cnt++;
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                    
                }
            }
            time++;
        }
        return (c==cnt)?time:-1;
    }
};