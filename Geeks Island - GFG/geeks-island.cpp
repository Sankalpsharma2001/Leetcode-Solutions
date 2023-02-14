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
    void dfs(int x,int y,int N,int M,vector<vector<int>> &mat,vector<vector<int>> &vis)
    {
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        vis[x][y]=1;
        for(int dir=0;dir<4;dir++)
        {
            int newX=x+dx[dir];
            int newY=y+dy[dir];
            if(isValid(newX,newY,N,M) && mat[newX][newY]>=mat[x][y] && vis[newX][newY]==0)
            {
                dfs(newX,newY,N,M,mat,vis);
            }
        }
    }
    int water_flow(vector<vector<int>> &mat,int N,int M){
    // Write your code here.
    vector<vector<int>> vis1(N,vector<int>(M,0));
    
    vector<vector<int>> vis2(N,vector<int>(M,0));
    
      for(int i=0;i<N;i++)
      {
          dfs(i,0,N,M,mat,vis1);
          dfs(i,M-1,N,M,mat,vis2);
      }
       for(int i=0;i<M;i++)
      {
          dfs(0,i,N,M,mat,vis1);
          dfs(N-1,i,N,M,mat,vis2);
      }
       int ans=0;
        for(int i=0;i<N;i++)
       {
           for(int j=0;j<M;j++)
           {
               if(vis2[i][j] && vis1[i][j])
               {
                ans++;
               }
           }
       }
       return ans;
      
      
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends