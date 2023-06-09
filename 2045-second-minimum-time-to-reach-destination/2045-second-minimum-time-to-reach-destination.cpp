class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);
        for(auto &e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);           
        }
        
        vector<int> dis1(n+1,1e9),dis2(n+1,1e9);
        queue<pair<int,int>> q;
        q.push({0,1}); // time, node
        dis1[0]=0;
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            int t=f.first;
            int node=f.second;
            int val=t/change;
            if(val%2)
                t=(change)*(val+1);
            for(auto &it:adj[node])
            {
                int tt=time+t;
                if(tt<dis1[it])
                {
                    dis2[it]=dis1[it];
                    dis1[it]=tt;
                    q.push({tt,it});
                }
                else if(tt<dis2[it] && tt>dis1[it])
                {
                    dis2[it]=tt;
                    q.push({tt,it});
                }
            }
           
        }
        return dis2[n];
        
    }
};