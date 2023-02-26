class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto &it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
         queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            topo.push_back(t);
            for(auto &it:adj[t])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        if(topo.size()==numCourses)
        return topo;
        return {};
    }
};