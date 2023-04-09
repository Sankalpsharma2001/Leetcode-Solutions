class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
          priority_queue<pair<long long,pair< int, int>>, vector<pair<long long,pair< int, int>>>, greater<pair<long long,pair< int, int>>>> pq;
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        pq.push({1,{0,0}});
      
        while(!pq.empty()){
            auto it=pq.top(); pq.pop();
            int a=it.first,b=it.second.first,c=it.second.second;
            if(b==n-1 && c==m-1) return a;
            if(grid[b][c]==0) continue;
            for(int i=c+1;i<m && i<=grid[b][c]+c;i++){
                if(!visited[b][i]){
                     visited[b][i]=1;
                    if(b==n-1 && i==m-1)
                        return a+1;
                    pq.push({a+1,{b,i}});
                }
            }
            for(int i=b+1;i<n && i<=grid[b][c]+b;i++){
                if(!visited[i][c]){
                     visited[i][c]=1;
                     if(i==n-1 && c==m-1)
                        return a+1;
                    pq.push({a+1,{i,c}});
                }
            }
        }
        return -1;
    }
};