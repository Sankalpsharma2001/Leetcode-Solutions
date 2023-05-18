class Solution {
public:
  
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        for(auto &it:edges)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
         vector<int> ans,vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
              
                ans.push_back(i);
            }
        }
      
        return ans;
    }
};