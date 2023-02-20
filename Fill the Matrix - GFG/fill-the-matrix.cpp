//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    bool isValid(int x,int y,int n,int m)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
    int minIteration(int N, int M, int x, int y){    
        // code here
        vector<vector<int>> vis(N,vector<int>(M,0));
        
        if(N==1 && M==1)
        return 0;
        x--,y--;
        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y]=1;
        int ans=0;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        int t=N*M;
        t--;
        int step=0;
        while(!q.empty() && t>0)
        {
            int sz=q.size();
            while(sz--)
            {
              auto p=q.front();
              q.pop();
              int xx=p.first;
              int yy=p.second;
              for(int dir=0;dir<4;dir++)
              {
                  int newx=xx+dx[dir];
                  int newy=yy+dy[dir];
                  if(isValid(newx,newy,N,M) && !vis[newx][newy])
                  {
                      vis[newx][newy]=1;
                      q.push({newx,newy});
                      t--;
                  }
              }
            }
            step++;
        }
        return step;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends