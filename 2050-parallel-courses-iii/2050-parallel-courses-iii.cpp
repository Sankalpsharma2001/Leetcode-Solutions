class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1,0);
        for(auto &it:relations)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        vector<int> dis(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(indegree[i]==0)
            {q.push(i);
            dis[i]=time[i-1];}
        }
         
        int ans=0;
        
        while(!q.empty())
        {
            
                auto f=q.front();
                    q.pop();
                
                for(auto &it:adj[f])
                {
                    dis[it]=max(dis[it],dis[f]+time[it-1]);
                  indegree[it]--;
                    if(indegree[it]==0)
                    {
                        q.push(it);
                    }
                }
           
        }
        return *max_element(dis.begin(),dis.end());
        
        
    }
};