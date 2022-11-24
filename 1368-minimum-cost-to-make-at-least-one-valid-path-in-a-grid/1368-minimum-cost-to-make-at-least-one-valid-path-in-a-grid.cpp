class com{
    public:
    bool operator()(vector<int>&a,vector<int> &b)
    {
        return a[2]>b[2];
    }
};
class Solution {
    bool isValid(int x,int y,int n,int m)
    {
        return x>=0 && y>=0 && x<n  && y<m;
    }   
        
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,com> pq;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        pq.push({0,0,0});
       
        while(!pq.empty())
        {
            vector<int> t=pq.top();
            pq.pop();
            int cost=t[2];
            int x=t[0];
            int y=t[1];
            if(x==n-1 && y==m-1)
                return cost;
            if(vis[x][y]==1) continue;
           vis[x][y]=1;
            for(int ind=0;ind<4;ind++)
            {
                int nx=x+dx[ind];
                int ny=y+dy[ind];
              if(isValid(nx,ny,n,m) && !vis[nx][ny]) 
              {
                  
                  if(grid[x][y]==ind+1)
                  {
                      pq.push({nx,ny,cost});
                  }
                  else
                  {
                      pq.push({nx,ny,cost+1});
                  }
              }
            }
        }
        return -1;
    }
};