class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
       int n=colors.size();
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n,0);
        for(auto &it:edges)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
          if(indegree[i]==0) q.push(i);   
        }
          vector<vector<int>> count(n, vector<int>(26));
        int c=0,ans=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count[node][colors[node]-'a']++;
            ans=max(ans, count[node][colors[node]-'a']);
            c++;
            for(auto &it:adj[node])
            {
                for(int i=0;i<26;i++)
                {
                    count[it][i]=max(count[it][i],count[node][i]);
                }
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return c<n?-1:ans;
    }
};