//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    public:
    vector<int> parent,size,rank;
    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
            size[i]=1;
        }
    }
    int findParent(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionByRank(int a,int b)
    {
        a=findParent(a);
        b=findParent(b);
         if(a==b) return;
        if(rank[a]<rank[b])
        {
            parent[a]=b;
            
        }
        else if(rank[a]>rank[b])
        {
            parent[b]=a;
        }
        else
        {
            parent[b]=a;
            rank[a]++;
        }
        
    }
    void unionBySize(int a,int b)
    {
         a=findParent(a);
        b=findParent(b);
        if(a==b) return;
        if(size[a]<size[b])
        {
            parent[a]=b;
            size[b]+=size[a];
        }
        else
        {
            parent[b]=a;
            size[a]+=size[b];
        }
    }
};
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    DisjointSet ds(V+1);
	    for(int i=0;i<V;i++)
	    {
	        for(auto &it:adj[i])
	        {
	            if(ds.findParent(it)==ds.findParent(i) && it>i)
	            {
	                return 1;
	            }
	            else
	            {
	                ds.unionBySize(i,it);
	            }
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends