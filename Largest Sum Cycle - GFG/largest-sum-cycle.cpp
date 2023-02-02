//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define ll long long
class Solution
{
  public:
  
  ll ans=-1;
  void dfs(int node,int par,vector<ll> &vis,vector<ll> &dvis,vector<vector<ll>> &adj,vector<ll> &sum)
    {
        if(par==-1)
        sum[node]=node;
        else
        sum[node]=sum[par]+node;
        vis[node]=1;
       dvis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
           
            dfs(it,node,vis,dvis,adj,sum);
           
        }
        else if(dvis[it]==1)
        {
            
            ans=max(ans,1ll*(sum[node]-sum[it]+it));
           
            
        }
    }
    dvis[node]=0;
    }
  long long largestSumCycle(int N, vector<int> Edge)
  {
    // code here
    vector<vector<long long>> adj(N);
    for(int i=0;i<N;i++)
    {
        if(Edge[i]!=-1)
        adj[i].push_back(Edge[i]);
    }
    vector<ll> vis(N+1),dvis(N+1),sum(N+1);
    for(int i=0;i<N;i++)
    {
        if(!vis[i])
        {
            dfs(i,-1,vis,dvis,adj,sum);
        }
    }
    
    return ans;
     
    
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends