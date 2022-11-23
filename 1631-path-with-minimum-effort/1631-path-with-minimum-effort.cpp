#define pipi pair<int,pair<int,int>> 
class Solution {
public:
    bool isValid(int x,int y,int n,int m)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        priority_queue<pipi,vector<pipi>,greater<pipi>> pq;
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();
            int dif=top.first;
            int x=top.second.first;
            int y=top.second.second;
            if(dis[x][y]<dif) continue;
            if(x==n-1 && y==m-1)
                return dif;
            
            for(int ind=0;ind<4;ind++)
            {
                int xx=x+dx[ind];
                int yy=y+dy[ind];
                if(!isValid(xx,yy,n,m)) continue;
                int newdif=max(abs(heights[xx][yy]-heights[x][y]),dif);
                if(dis[xx][yy]<=newdif) continue;
                    dis[xx][yy]=newdif;
                    pq.push({newdif,{xx,yy}});
                
            }
        }
        return 0;
    }
};