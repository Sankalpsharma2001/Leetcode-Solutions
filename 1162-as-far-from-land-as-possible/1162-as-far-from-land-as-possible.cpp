class Solution {
public:
    bool isvalid(int x,int y,int n,int m)
    {
        return (x>=0 && y>=0 && x<n && y<m);
    }
    int maxDistance(vector<vector<int>>& grid) {
       ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {    q.push({i,j});
                 dis[i][j]=0;
                }
                            
            }
        }
        if(q.size()==n*m or q.empty())
            return -1;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty())
        {
             pair<int,int> p=q.front();
             q.pop();
            for(int i=0;i<4;i++)
            {
                int x=dx[i]+p.first;
                int y=dy[i]+p.second;
                if(isvalid(x,y,n,m))
                {
                    if(dis[x][y]==1e9)
                    q.push({x,y});
                    dis[x][y]=min(dis[x][y],dis[p.first][p.second]+1);                    
                }
            }
             
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    res=max(res,dis[i][j]);
                }
            }
        }
        return res;
    }
};