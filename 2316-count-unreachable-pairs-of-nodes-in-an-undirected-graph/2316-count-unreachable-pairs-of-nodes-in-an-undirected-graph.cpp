class Solution {
public:
    int dfs(int node, vector<vector<int>> &adj,vector<int> &vis)
    {
        vis[node]=1;
        int c=1;
        for(auto &it:adj[node])
        {
            if(!vis[it])
                c+=dfs(it,adj,vis);
        }
        return c;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        for(auto &it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            
        }
        long long ans=0,rem=n;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
               int size=dfs(i,adj,vis);
                ans+=(size*(rem-size));
                rem-=size;
            }
        }
        return ans;
        
    }
};