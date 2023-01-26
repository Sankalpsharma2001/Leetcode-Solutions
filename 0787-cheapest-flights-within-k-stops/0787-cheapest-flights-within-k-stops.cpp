class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<vector<pair<int,int>>> adj(n);
        for(auto &it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
           
        }
        queue<pair<int,int>> q;
        vector<int> dis(n,INT_MAX);
        q.push({src,0});
        dis[src]=0;
        int ans=INT_MAX;
        int stops=0;
        while(stops<=k && !q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                pair<int,int> t=q.front();
                q.pop();
                int node=t.first;
                int distance=t.second;
                if(distance>dis[node]) continue;
                dis[node]=distance;
                for(auto &it:adj[node])
                {
                    if(it.second+distance>ans) continue;
                    if(it.first==dst)
                    {
                        ans=min(ans,it.second+distance);
                    }
                    q.push({it.first,it.second+distance});
                   
                }
            }
            stops++;
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};