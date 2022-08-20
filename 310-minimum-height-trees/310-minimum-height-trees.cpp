class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> degree(n,0),adj[n+1];
        if(n==1)
            return {0};
        for(auto &x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            degree[x[0]]++;
            degree[x[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(degree[i]==1)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.clear();
            int sz=q.size();
            while(sz--)
            {
                auto x=q.front();
                q.pop();
                ans.push_back(x);
                for(auto &it:adj[x])
                {
                    degree[it]--;
                    if(degree[it]==1)
                    {
                        q.push(it);
                    }
                }
            }
        }
     return ans;   
    }
};