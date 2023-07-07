//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
       void bfs(int node , int n, int &end , int &pipe , vector<int>&pipes, vector<int>adj[])
    {
        queue<int> q;
        vector<int> vis(n+1 , 0);
        
        q.push(node);
        vis[node] = 1;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            end = node;
            pipe = min(pipe , pipes[node]);
            
            for(auto it : adj[node]){
                if(vis[it] == 0 ){
                     q.push(it);
                     vis[it] = 1;
                }
            }
        }
    }
   void dfs(int node, int par , int n, int &end , int &pipe , vector<int>&pipes, vector<int>adj[])
   {
       pipe=min(pipe,pipes[node]);
       end=node;
       for(auto &it:adj[node])
       {
           if(it!=par)
           {
               dfs(it,node,n,end,pipe,pipes,adj);
           }
       }
   }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<int> adj[n+1];
        for(int i = 0; i < p ; i++){
            adj[a[i]].push_back(b[i]);
        }
        
        vector<int> present(n+1 , false);
        for(int i = 0; i < p ; i++){
            present[a[i]] = true;
            present[b[i]] = true;
        }
        
        vector<int>pipes(n+1 , 1e9);
        for(int i = 0 ; i < p ; i++){
            pipes[b[i]] = d[i];
        
        }
        
        vector<int> indegree(n+1);
        for(int i = 1 ; i <= n ; i++){
            for(auto &it : adj[i]){
                indegree[it]++;
            }
        }
        
        vector<vector<int>> ans;
        
        for(int i = 1 ; i <= n  ; i++){
            if(indegree[i] == 0 && present[i]){
                int start = i;
                int end , pipe = 1e5;
                // bfs(i , n , end , pipe , pipes , adj);
                dfs(i,-1 , n , end , pipe , pipes , adj);
                // cout<<start<<" "<<end<<" "<<pipe<<endl;
                ans.push_back({start , end , pipe});
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends