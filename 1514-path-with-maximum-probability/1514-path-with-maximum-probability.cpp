class Solution {
public:
  
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n+1);
       
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});

        }
        vector<double> prob(n,0);
       priority_queue<pair<double,int>> pq;
        pq.push({1.00,start});
        prob[start]=1;
        while(!pq.empty())
        {
            auto f=pq.top();
            pq.pop();
            double p=f.first;
            int pos=f.second;
            for(auto &it:adj[pos])
            {
                if(p*it.second>prob[it.first])
                {
                    prob[it.first]=p*it.second;
                    pq.push({prob[it.first],it.first});
                }
            }
        }
        return prob[end];
    }
};