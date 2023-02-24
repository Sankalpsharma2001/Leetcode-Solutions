//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> Dijkstra(int src,int des,vector<vector<pair<int,int>>> &adj,int n)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dis(n+1,1e9);
        
        pq.push({0,src});
        dis[src]=0;
        while(!pq.empty())
        {
            auto t=pq.top();
            pq.pop();
            int u=t.second;
           
            for(auto it:adj[u])
            {
              int v=it.first;
              int w=it.second;
              if(dis[v]>dis[u]+w)
              {
                  dis[v]=dis[u]+w;
                  pq.push({dis[v],v});
              }
            }
        }
        return dis;
    }
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        // code here
        vector<vector<pair<int,int>>> adj(n+1);
        vector<vector<int>> curve;
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            curve.push_back({edges[i][0],edges[i][1],edges[i][3]});
        }
        
        // a to b   dis_a-b 
        // b to a   dis_b-a
        vector<int> dis_ab=Dijkstra(a,b,adj,n);
        vector<int> dis_ba=Dijkstra(b,a,adj,n);
        int ans=dis_ab[b];
         for(int i=0;i<m;i++)
         {
             int u=curve[i][0],v=curve[i][1],w=curve[i][2];
             ans=min(ans,dis_ab[u]+w+dis_ba[v]);
             ans=min(ans,dis_ab[v]+w+dis_ba[u]);
         }
       if(ans==1e9) return -1;
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}
// } Driver Code Ends