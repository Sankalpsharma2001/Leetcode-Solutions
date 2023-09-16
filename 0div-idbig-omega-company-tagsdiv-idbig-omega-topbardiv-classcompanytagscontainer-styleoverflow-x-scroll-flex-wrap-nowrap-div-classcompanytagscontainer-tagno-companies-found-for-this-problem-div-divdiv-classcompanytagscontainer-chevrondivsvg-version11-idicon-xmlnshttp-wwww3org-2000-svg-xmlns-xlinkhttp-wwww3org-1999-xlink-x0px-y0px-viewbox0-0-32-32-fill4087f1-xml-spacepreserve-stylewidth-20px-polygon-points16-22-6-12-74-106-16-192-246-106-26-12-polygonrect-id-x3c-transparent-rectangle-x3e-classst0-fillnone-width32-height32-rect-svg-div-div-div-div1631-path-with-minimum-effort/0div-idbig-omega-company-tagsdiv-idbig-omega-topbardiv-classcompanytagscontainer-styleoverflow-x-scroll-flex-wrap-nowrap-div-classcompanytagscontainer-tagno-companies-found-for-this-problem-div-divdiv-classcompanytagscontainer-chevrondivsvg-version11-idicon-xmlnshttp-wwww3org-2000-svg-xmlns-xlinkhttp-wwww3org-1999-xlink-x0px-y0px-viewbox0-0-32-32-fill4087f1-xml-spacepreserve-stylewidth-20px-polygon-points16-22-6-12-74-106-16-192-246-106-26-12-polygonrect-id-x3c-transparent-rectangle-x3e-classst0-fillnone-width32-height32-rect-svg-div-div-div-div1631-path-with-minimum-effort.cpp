#define pipii pair<int,pair<int,int>> 
class Solution {
public:
     bool check(vector<vector<int>>& a, int mid){
        int n = a.size();
        int m = a[0].size();
        
         vector<vector<bool>> vis(n, vector<bool> (m,false));
       
        queue<pair<int,int>> q;
        
        q.push({0,0});
        vis[0][0]= true;
        vector<int> xdir= {1,0,-1,0};
        vector<int> ydir = {0,-1,0,1};
        while(!q.empty()){
            auto temp = q.front(); q.pop();
            
            if(temp.first == n-1 && temp.second == m-1) return true;
            
            for(int  k=0; k<4; ++k){
                int x = temp.first + xdir[k];
                int y = temp.second + ydir[k];
                
                if(x<0 || y<0 || x>=n || y>=m || vis[x][y] || abs(a[x][y] - a[temp.first][temp.second]) > mid) continue;
                
                q.push({x,y});
                vis[x][y] = true;
            }
        }
        
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        int l = 0, h = 1e6;
        
        int ans=0;
        while(l<=h){ 
            int mid = l + (h-l)/2;
            
            if(check(heights,mid)) {
                ans=mid;
                h= mid-1;}
            else {l = mid+1;}
        }
        
        
        return ans;
    }
};