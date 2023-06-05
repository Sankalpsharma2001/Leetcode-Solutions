#define pipii pair<int,pair<int,int>>
class Solution {
public:
    bool isValid(int &x,int &y,int &m,int &n)
    {
        return x>=0 && y>=0 && x<m && y<n;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
         int trap = 0;
         int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<pipii,vector<pipii>,greater<pipii>> pq;
          // top and bottom cells 
        for(int i = 0; i < n; i++) {
            pq.push({heightMap[0][i],{ 0, i}}),
            pq.push({heightMap[m-1][i], {m-1, i}});
            visited[0][i] = true, visited[m-1][i] = true;
        }
          // right and left cells
        for(int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}}),
            pq.push({heightMap[i][n-1], {i, n-1}});
            visited[i][0] = true, visited[i][n-1] = true;
        }
            
        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();
            int h=top.first;
            int r=top.second.first;
            int c=top.second.second;
            for(int i=0;i<directions.size();i++)
            {
                int nr=directions[i][0]+r,nc=directions[i][1]+c;
                if(isValid(nr,nc,m,n) && !visited[nr][nc] )
                {
                  visited[nr][nc]=1;
                   if(heightMap[nr][nc]<h)
                   {
                       trap+=(h-heightMap[nr][nc]);
                   }
                    
                   pq.push({max(heightMap[nr][nc],h),{nr,nc}}); 
                    
                }
            }
            
            
        }
        return trap;
    }
};