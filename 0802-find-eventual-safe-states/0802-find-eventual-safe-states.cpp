class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> adjRev[V];
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto &it:graph[i])
            {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            q.push(i);
            
        }
        vector<int> topo;
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            topo.push_back(f);
            for(auto &it:adjRev[f])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;   
    }
};