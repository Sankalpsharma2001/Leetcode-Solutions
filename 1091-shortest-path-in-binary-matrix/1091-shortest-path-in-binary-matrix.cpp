class Solution {
    bool isValid(int x,int y,int n)
    {
        return x>=0 && y>=0 && x<n && y<n;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        queue<pair<int,int>> q;
        vector<vector<int>> dis(n,vector<int>(n,1e9));
        int dx[8]={-1,-1,-1,0,0,1,1,1};
        int dy[8]={-1,0,1,-1,1,0,1,-1};
        vector<vector<int>> vis(n,vector<int>(n,0));
        dis[0][0]=1;
        q.push({0,0});
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            for(int ind=0;ind<8;ind++)
            {
                int x=t.first+dx[ind];
                int y=t.second+dy[ind];
                if(isValid(x,y,n))
                {
                    if(dis[x][y]==1e9 && grid[x][y]==0)
                    {
                        dis[x][y]=(dis[x][y],dis[t.first][t.second]+1);
                        q.push({x,y});
                    }
                }
            }
        }
        
        return dis[n-1][n-1]==1e9?-1:dis[n-1][n-1];
    }
};