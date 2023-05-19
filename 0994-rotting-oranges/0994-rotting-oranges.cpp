class Solution {
public:
    bool issafe(int x,int y,int n,int m)
    {
        return x>=0 and y>=0 and x<n and y<m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        queue<pair<int,int>> q;
         vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    cnt++;
                }
                else if(grid[i][j]==2)
                {q.push(make_pair(i,j));
                vis[i][j]=1;}
            }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
       
        int time=0;
        while(!q.empty() and cnt>0)
        {
            time++;
            int sz=q.size();
            while(sz--)
            {
                pair<int,int> p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                for(int k=0;k<4;k++)
                {
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(issafe(x,y,n,m) and grid[x][y]==1 and !vis[x][y])
                    {
                        cnt--;
                        grid[x][y]=2;
                        vis[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
        }
        return (cnt==0)?time:-1;
    }
};