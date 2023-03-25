class Solution {
public:
    bool isValid(int x,int y,int m,int n)
    {
        return x>=0 && y>=0 && x<m && y<n;
    }
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m=grid.size(),n=grid[0].size();
         vector<vector<int>> ans;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        int dis=0;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
             auto f=q.front();
                q.pop();
              int x=f.first,y=f.second;
                if(vis[x][y]) continue;
                if(grid[x][y]==0) continue;
                vis[x][y]=1;
                if(grid[x][y]!=1)
                {
                    int val=grid[x][y];
                    if(val>=pricing[0] && val<=pricing[1])
                    {
                        pq.push({dis,val,x,y});
                    }
                  
                }
                for(int dir=0;dir<4;dir++)
                {
                    int newX=x+dx[dir],newY=y+dy[dir];
                    if(isValid(newX,newY,m,n) && vis[newX][newY]==0)
                    {
                        q.push({newX,newY});
                    }
                }
                
                
            }
            dis++;
        }
        while(!pq.empty() && k-->0)
        {
            auto f=pq.top();
            pq.pop();
            int x=f[2],y=f[3];
            ans.push_back({x,y});
        }
        return ans;
        
    }
};