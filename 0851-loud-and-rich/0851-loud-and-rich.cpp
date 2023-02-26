class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int> adj[n+1];
        vector<int> indegree(n+1,0);
        for(auto it:richer)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
         queue<int> q;
        
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
             ans[i]=i;
            if(indegree[i]==0)
                q.push(i);
        }
       
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            // cout<<f<<" ";
            for(auto &it:adj[f])
            {
                //if parent node having more money is quieter than update
                if(quiet[ans[it]]>quiet[ans[f]]) // it has more money than f 
                {
                   ans[it]=ans[f];
                }
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
       
        
        
        return ans;
    }
};