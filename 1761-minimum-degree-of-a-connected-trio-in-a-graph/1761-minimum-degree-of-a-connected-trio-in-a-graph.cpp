class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
         vector<vector<int>> adj(n+1),vis(n+1,vector<int>(n+1,0));
        
        for(auto &it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            vis[it[0]][it[1]]=1;
            vis[it[1]][it[0]]=1;
        }
        int ans=1e9;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    if(vis[i][j] && vis[j][k] && vis[i][k])
                    {
                        int edge=adj[i].size()+adj[j].size()+adj[k].size()-6;
                        ans=min(ans,edge);
                    }
                        
                }
            }
        }
        return ans==1e9?-1:ans;
    }
};