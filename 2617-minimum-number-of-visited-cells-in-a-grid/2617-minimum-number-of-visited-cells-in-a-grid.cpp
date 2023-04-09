class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
            priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        pq.push({1,0,0});
        visited[0][0]=1;
        while(!pq.empty()){
            auto it=pq.top(); pq.pop();
            int a=it[0],b=it[1],c=it[2];
            if(b==n-1 && c==m-1) return a;
           
            for(int i=c+1;i<m && i<=grid[b][c]+c;i++){
                if(!visited[b][i]){
                    visited[b][i]=1;
                      if(b==n-1 && i==m-1)
                        return a+1;
                    pq.push({a+1,b,i});
                }
            }
            for(int i=b+1;i<n && i<=grid[b][c]+b;i++){
                if(!visited[i][c]){
                    visited[i][c]=1;
                      if(i==n-1 && c==m-1)
                        return a+1;
                    pq.push({a+1,i,c});
                }
            }
        }
        return -1;
    }
};