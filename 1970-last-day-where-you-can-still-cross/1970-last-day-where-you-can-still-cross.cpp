class Solution {
public:
    bool isSafe(int &x,int &y,int &n,int &m)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
    bool canWalk(vector<vector<int>>& cells,int &row,int &col,int &mid)
    {
        vector<vector<int>> grid(row,vector<int>(col,0));
        for(int i=0;i<mid;i++) grid[cells[i][0]-1][cells[i][1]-1]=1;
        queue<pair<int,int>> q;
        for(int i=0;i<col;i++)
        {
            if(grid[0][i]==0)
            {
                q.push({0,i});
                grid[0][i]=1;
            }
           
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==row-1) return true;
            for(int dir=0;dir<4;dir++)
            {
                int xx=x+dx[dir];
                int yy=y+dy[dir];
                if(isSafe(xx,yy,row,col) && grid[xx][yy]==0)
                {
                    grid[xx][yy]=1;
                    q.push({xx,yy});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int &row, int &col, vector<vector<int>>& cells) {
        int low=0,high=row*col,ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(canWalk(cells,row,col,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
        
    }
};