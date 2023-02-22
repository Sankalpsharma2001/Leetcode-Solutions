//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pipii pair<int,pair<int,int>> 

class Solution {
  public:
    bool isValid(int x,int y,int n,int m)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
         int n=heights.size(),m=heights[0].size();
        priority_queue<pipii,vector<pipii>,greater<pipii>> pq;
         pq.push({0,{0,0}});
       
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
         dis[0][0]=0;
        while(!pq.empty())
        {
            auto t=pq.top();
            pq.pop();
            int dif=t.first;
            int x=t.second.first;
            int y=t.second.second;
            if(x==n-1 && y==m-1) return dis[x][y];
            for(int dir=0;dir<4;dir++)
            {
                int newX=x+dx[dir];
                int newY=y+dy[dir];
                if(isValid(newX,newY,n,m))
                {
                    int val=max(abs(heights[newX][newY]-heights[x][y]),dif);
                    if(val<dis[newX][newY])
                    {
                        dis[newX][newY]=val;
                        pq.push({val,{newX,newY}});
                    }
                }
            }
            
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends