class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
   int n=points.size();
vector<pair<int,int>> adj[n+1];
        
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
             adj[i].push_back({j,wt});   
                  adj[j].push_back({i,wt});   
            }
        }
        vector<int> mst(n+1,0),dis(n+1,INT_MAX);
       int ans=0;
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
         dis[0]=0;
        while(!pq.empty())
        {
            auto f=pq.top();
            pq.pop();
            int u=f.second;
            if(mst[u]) continue;
            mst[u]=1;
            ans+=f.first;
            for(auto &it:adj[u])
            {
                int v=it.first;
                if(!mst[v])
                {
                    dis[v]=it.second;
                    pq.push({it.second,v});
                }
            }
        }
      
        return ans;
        
    }
};