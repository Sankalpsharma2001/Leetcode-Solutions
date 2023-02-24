class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<vector<pair<int,int>>> adj(n);
        for(auto &it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
           
        }
       queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dis(n+1,1e9);
        dis[src]=0;
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            int stop=f.first;
            int u=f.second.first;
            int dist=f.second.second;
            if(stop>k) continue;
            for(auto &it:adj[u])
            {
                int v=it.first;
                int w=it.second;
                if(dist+w<dis[v] && stop<=k)
                {
                    dis[v]=dist+w;
                    q.push({stop+1,{v,dis[v]}});
                }
            }
        }
       if(dis[dst]==1e9) return -1;
        return dis[dst];
    }
};