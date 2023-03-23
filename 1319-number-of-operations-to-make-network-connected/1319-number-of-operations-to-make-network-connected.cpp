class Solution {
public:
    void dfs(  vector<vector<int>> &adj,vector<int> &vis,int &node)
    {
        vis[node]=1;
        for(auto &it:adj[node])
        {
            if(!vis[it])
                dfs(adj,vis,it);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<vector<int>> adj(n+1);
        for(auto &it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n+1,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(adj,vis,i);
                cnt++;
            }
        }
        return cnt-1;
    }
};