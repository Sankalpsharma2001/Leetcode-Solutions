class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
          int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(isWater[i][j] == 1){
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int dx[4] = {0,0,-1,1};
            int dy[4] = {-1,1,0,0};
            
            for(int i = 0;i<4;i++){
                int xx = x + dx[i];
                int yy = y + dy[i];
                
                if(xx>=0 && xx<m && yy>=0 && yy<n && dis[xx][yy] > 1 + dis[x][y]){
                    dis[xx][yy] = 1 + dis[x][y];
                    q.push({xx,yy});
                }
            }
        }
        return dis;
    }
};