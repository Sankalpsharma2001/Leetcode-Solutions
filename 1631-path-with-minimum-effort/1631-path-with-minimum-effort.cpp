class Solution {
public:
    bool isValid(vector<vector<int>> &heights,int mid)
    {
        queue<pair<int,int>> q;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        q.push({0,0});
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            int x=node.first;
            int y=node.second;
            if(x==n-1 && y==m-1)
                return true;
            for(int ind=0;ind<4;ind++)
            {
                int xx=dx[ind]+x;
                int yy=dy[ind]+y;
                if(xx<0 || xx>=n || yy<0 || yy>=m) continue;
                if(vis[xx][yy]) continue;
                if(abs(heights[xx][yy]-heights[x][y])<=mid) 
                {
                    vis[xx][yy]=1;
                    q.push({xx,yy});
                }
                
            }    
                
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        
       int l=0,r=1e9,ans=1e9;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(isValid(heights,mid))
            {
                ans=mid;
                r=mid-1;
            }
            
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};