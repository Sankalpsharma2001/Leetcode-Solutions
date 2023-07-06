//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int partyHouse(int n, vector<vector<int>> &adj){
            vector<int> degree(n+1, 0);
        for(int i=1; i<=n; i++){
            degree[i]+= adj[i].size();
        }
        
        queue<int> pending;
        for(int i=1; i<=n; i++){
            if(degree[i]== 1){
                pending.push(i);
                degree[i]--;
            }
        }
        
        int root= 0;
        while(!pending.empty()){
            int size= pending.size();
            
            for(int i=0; i<size; i++){
                int node= pending.front();
                pending.pop();
                
                root = node;
                
                for(int j=0; j<adj[node].size(); j++){
                    
                    degree[adj[node][j]]--;
                    if(degree[adj[node][j]]== 1){
                        pending.push(adj[node][j]);
                    }
                }
            }
        }
        
        pending.push(root);
        int ans= 0;
        vector<bool> visited(n+1, false);
        visited[root]= true;
        
        
        while(!pending.empty()){
            int size= pending.size();
            
            for(int i=0; i<size; i++){
                int node= pending.front();
                pending.pop();
                
                for(int j=0; j<adj[node].size(); j++){
                    
                    if(!visited[adj[node][j]]){
                        visited[adj[node][j]]= true;
                        pending.push(adj[node][j]);
                    }
                }
            }
            ans++;
        }
        
        return ans-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}
// } Driver Code Ends