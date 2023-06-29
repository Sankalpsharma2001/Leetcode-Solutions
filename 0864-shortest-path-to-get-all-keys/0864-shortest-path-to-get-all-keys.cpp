class Solution {
public:
    bool isValid(int x,int y,int n,int m,vector<string> &grid)
    {
        return x>=0 && y>=0 && x<n && y<m && grid[x][y]!='#';
    }
    int shortestPathAllKeys(vector<string>& grid) {
      
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> vis(n,vector<vector<int>>(m,vector<int>(64,0)));
        queue<pair<pair<int,int>,int>> q;
        int keys=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='@')
                {
                vis[i][j][0]=1;    
                q.push({{i,j},0});  
                }
                if(grid[i][j]>='a' && grid[i][j]<='f')
                    keys++;
            }
        }
       vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,-1,1};
        int moves=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
            auto f=q.front();
            q.pop();
            int i=f.first.first;
            int j=f.first.second;
            int mask=f.second;
            if(mask==((1<<keys)-1)) return moves;
                for(int dir=0;dir<4;dir++)
                {
                    int x=i+dx[dir];
                    int y=j+dy[dir];
                    int newMask=mask;
                    if(isValid(x,y,n,m,grid))
                    {
                        if(grid[x][y]>='a' && grid[x][y]<='f')
                        {
                           newMask=mask|(1<<(grid[x][y]-'a'));
                        }
                        else if(grid[x][y]>='A' && grid[x][y]<='F')
                        {
                            if(!(mask& (1<<(grid[x][y]-'A')))) continue; // we cant move 
                        }
                        if(!vis[x][y][newMask])
                        {
                            vis[x][y][newMask]=1;
                            q.push({{x,y},newMask});
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};