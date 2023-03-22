class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(edges.size()==0)
            return 1;
        if(target==1 && t>0) return 0;
        queue<pair<pair<int,int>,double>> q;
        vector<vector<int>> adj(n+1);
        for(auto &it:edges)
        {
            adj[it[0]].push_back(it[1]);
            
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n+1,0);
        vis[1]=1;
        q.push({{1,t},1.0});
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            double p=f.second;
            int node=f.first.first;
            int time=f.first.second;
            int sz=adj[node].size();
            if(node!=1) sz--;
            double p1=1/(1.0*(sz?sz:1));
            if(node==target)
            {
              if(time==0 || (adj[node].size()==1 && node!=1))
                  return p*p1;
                else
                    return 0;
            }
            
            
            for(auto &it:adj[node])
            {
                if(!vis[it])
                {
                 vis[it]=1;   
                    if(time)
                    q.push({{it,time-1},p*p1});
                }
            }
        }
        
        return 0;
    }
};