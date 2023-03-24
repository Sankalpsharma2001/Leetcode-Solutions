class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
         vector<pair<int,int>> adj[n+1];
        vector<int> vis(n+1,0);
        
        for(auto &it:connections)
        {
            adj[it[0]].push_back({it[1],1});
            adj[it[1]].push_back({it[0],0});
        }
        
        queue<int> q;
        q.push(0);
        vis[0]=1;
        int ans=0;
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            for(auto &it:adj[f])
            {
                if(!vis[it.first])
                {
                 ans+=it.second;
                    q.push(it.first);
                    vis[it.first]=1;
                }
            }
            
        }
        return ans;
        
    }
};