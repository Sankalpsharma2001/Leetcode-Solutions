class Solution {
    bool isValid(int x,int y,int n,int m)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // 1 right
        // 2 left
        // 3 lower
        // 4 upper
        vector<vector<int>> dis(n,vector<int>(m,1000));
        vector<pair<int,int>> p={{0,0},{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> q;
        q.push({0,0});
        dis[0][0]=0;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            int x=f.first;
            int y=f.second;
            
            for(int ind=0;ind<4;ind++)
            {
                int xx=dx[ind]+x;
                int yy=dy[ind]+y;
                if(isValid(xx,yy,n,m))
                {
                    if(dx[ind]==p[grid[x][y]].first && dy[ind]==p[grid[x][y]].second)
                    {
                        if(dis[xx][yy]>dis[x][y])
                        {dis[xx][yy]=dis[x][y];
                        q.push({xx,yy});
                        }
                    }
                    else
                    {
                        if(dis[xx][yy]>dis[x][y]+1)
                        {
                            dis[xx][yy]=dis[x][y]+1;
                            q.push({xx,yy});
                        }
                        
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};