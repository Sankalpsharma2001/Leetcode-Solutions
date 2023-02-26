#define pipi pair<int,pair<int,int>>
class Solution {
public:
    bool isValid(int x,int y,int n,int m)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
  
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
       
         if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        priority_queue<pipi,vector<pipi>,greater<pipi>> pq;
        pq.push({0,{0,0}});
        int time=0;
          int dx[4]={1,-1,0,0};
          int dy[4]={0,0,-1,1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        while(!pq.empty())
        {
            auto t=pq.top();
            pq.pop();
            int time=t.first;
            int x=t.second.first;
            int y=t.second.second;
              if(x==n-1 && y==m-1)
                    return time;
            if(vis[x][y]) continue;
            vis[x][y]=1;
                 for(int dir=0;dir<4;dir++)
               {
            int newX=x+dx[dir];
            int newY=y+dy[dir];
            if(isValid(newX,newY,n,m) && vis[newX][newY]==0)
            {
             
                int dif=(grid[newX][newY]-time)%2==0;
                int tt=max(time+1,grid[newX][newY]+dif);
                pq.push({tt,{newX,newY}});
            }
               }
           
            
        }
        return -1;

    }
};