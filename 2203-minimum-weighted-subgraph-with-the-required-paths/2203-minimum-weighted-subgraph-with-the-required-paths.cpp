#define ll long long
class Solution {
public:
    vector<ll> dijkstra(vector<vector<pair<int,int>>> &adj,int &src)
    {
        vector<ll> dis(adj.size(),LONG_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        dis[src]=0;
        while(!pq.empty())
        {
            auto t=pq.top();
            int d=t.first;
            pq.pop();
            if(dis[t.second]<d) continue;
            for(auto &it:adj[t.second])
            {
                int v=it.first;
                int w=it.second;
                if(dis[v]>dis[t.second]+w)
                {
                    dis[v]=dis[t.second]+w;
                    pq.push({dis[v],v});
                }
            }
        }
        return dis;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int &src1, int &src2, int &dest) {
        vector<vector<pair<int,int>>> adj(n),radj(n);
        
        for(auto &it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            
            radj[it[1]].push_back({it[0],it[2]});
        }
        vector<ll> a=dijkstra(adj,src1);
        vector<ll> b=dijkstra(adj,src2);
        vector<ll> c=dijkstra(radj,dest);
        long long ans=LONG_LONG_MAX;
        for(int i=0;i<n;i++)
        {
            if(a[i]==LONG_MAX || b[i]==LONG_MAX || c[i]==LONG_MAX) continue;
            ans=min(ans,1ll*(a[i]+b[i]+c[i]));
        }
        return ans==LONG_LONG_MAX?-1:ans;
    }
};