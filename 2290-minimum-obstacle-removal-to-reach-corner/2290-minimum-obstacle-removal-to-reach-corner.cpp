class Solution {
public:
    bool isValid(int x,int y,int n,int m)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>obstacle(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>> q;
        // obs i,j
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        q.push({0,{0,0}});
        obstacle[0][0]=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto f=q.front();
                q.pop();
                int obs=f.first;
                int x=f.second.first;
                int y=f.second.second;
                for(int dir=0;dir<4;dir++)
                {
                    int newX=x+dx[dir];
                    int newY=y+dy[dir];
                    if(isValid(newX,newY,n,m))
                    {
                       
                            if(obstacle[newX][newY]>obstacle[x][y]+(grid[newX][newY]))
                        {
                          obstacle[newX][newY]=obstacle[x][y]+(grid[newX][newY]);
                       
                            q.push({obs+(grid[newX][newY]),{newX,newY}});
                        
                            }     
                             
                    }
                }
            }
        }
        return obstacle[n-1][m-1];
    }
};