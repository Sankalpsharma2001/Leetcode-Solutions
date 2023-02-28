class Solution {
public:
    bool isValid(int x,int y,int n,int m)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<vector<long long int>> q;
        vector<vector<long long int>> dis(n,vector<long long int>(m,1e12));
        // the fire coordinates pushing in queue so what from this we can calculate the distance to all other nodes at which time it gets fire
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    dis[i][j]=0;
                    q.push({i,j});
                }
                else if(grid[i][j]==2)
                {
                    dis[i][j]=-1;
                }
            }
        }
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        int level=1;
        while(q.size())
        {
            int size=q.size();
            while(size--)
            {
                auto temp=q.front();
                q.pop();
                int x=temp[0];
                int y=temp[1];
                for(int dir=0;dir<4;dir++)
                {
                    int nx=x+dx[dir];
                    int ny=y+dy[dir];
                    if(isValid(nx,ny,n,m) && dis[nx][ny]==1e12 && grid[nx][ny]==0)
                    {
                        dis[nx][ny]=level;
                        q.push({nx,ny});
                    }
                }
            }
            level++;
        }
    
        
        int low=0,high=1e9,ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(dis,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if(high==1e9) return 1e9;
        return ans;
    }
    bool check(vector<vector<long long int>> &dis,int mid)
    {  int n=dis.size(),m=dis[0].size();
         queue<vector<long long int>> q;
        q.push({0,0,mid});
        vector<vector<int>> vis(n,vector<int>(m,0));
       int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
     
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            int x=f[0],y=f[1],t=f[2];
            vis[x][y]=1;
            if(x==n-1 && y==m-1)
                return true;
            
            for(int dir=0;dir<4;dir++)
            {
                int newX=x+dx[dir];
                int newY=y+dy[dir];
                if(isValid(newX,newY,n,m) && vis[newX][newY]==0 && dis[newX][newY]!=-1)
                {
                    if(dis[newX][newY]>t+1)
                    {
                        q.push({newX,newY,t+1});
                    }
                    else if(newX==n-1 && newY==m-1 && dis[newX][newY]>=t+1)
                    {
                        q.push({newX,newY,t+1});
                    }
                }
            }
            
        }
     return false;
     
     
    }
};